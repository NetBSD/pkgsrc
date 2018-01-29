$NetBSD: patch-player_lua_ytdl__hook.lua,v 1.1 2018/01/29 21:54:22 leot Exp $

Sync ytdl_hook.lua script with commit 2a0f9fc1588d8bda51a6340197c54285f3f62755
in order to fix CVE-2018-6360.

Please note that this completely omits hunks that need `on_load_fail' hook that
was implemented post-0.27.

--- player/lua/ytdl_hook.lua.orig	2018-01-28 10:58:02.151884824 +0000
+++ player/lua/ytdl_hook.lua
@@ -15,6 +16,18 @@ local ytdl = {
 
 local chapter_list = {}
 
+function Set (t)
+    local set = {}
+    for _, v in pairs(t) do set[v] = true end
+    return set
+end
+
+local safe_protos = Set {
+    "http", "https", "ftp", "ftps",
+    "rtmp", "rtmps", "rtmpe", "rtmpt", "rtmpts", "rtmpte",
+    "data"
+}
+
 local function exec(args)
     local ret = utils.subprocess({args = args})
     return ret.status, ret.stdout, ret
@@ -71,6 +84,15 @@ local function edl_escape(url)
     return "%" .. string.len(url) .. "%" .. url
 end
 
+local function url_is_safe(url)
+    local proto = type(url) == "string" and url:match("^(.+)://") or nil
+    local safe = proto and safe_protos[proto]
+    if not safe then
+        msg.error(("Ignoring potentially unsafe url: '%s'"):format(url))
+    end
+    return safe
+end
+
 local function time_to_secs(time_string)
     local ret
 
@@ -182,6 +204,9 @@ local function edl_track_joined(fragment
 
     for i = offset, #fragments do
         local fragment = fragments[i]
+        if not url_is_safe(join_url(base, fragment)) then
+            return nil
+        end
         table.insert(parts, edl_escape(join_url(base, fragment)))
         if fragment.duration then
             parts[#parts] =
@@ -191,16 +216,63 @@ local function edl_track_joined(fragment
     return edl .. table.concat(parts, ";") .. ";"
 end
 
+local function has_native_dash_demuxer()
+    local demuxers = mp.get_property_native("demuxer-lavf-list")
+    for _,v in ipairs(demuxers) do
+        if v == "dash" then
+            return true
+        end
+    end
+    return false
+end
+
+local function valid_manifest(json)
+    local reqfmt = json["requested_formats"] and json["requested_formats"][1] or {}
+    if not reqfmt["manifest_url"] and not json["manifest_url"] then
+        return false
+    end
+    local proto = reqfmt["protocol"] or json["protocol"] or ""
+    return (has_native_dash_demuxer() and proto == "http_dash_segments") or
+        proto:find("^m3u8")
+end
+
 local function add_single_video(json)
     local streamurl = ""
+    local max_bitrate = 0
+    local reqfmts = json["requested_formats"]
+
+    -- prefer manifest_url if present
+    if valid_manifest(json) then
+        local mpd_url = reqfmts and reqfmts[1]["manifest_url"] or
+            json["manifest_url"]
+        if not mpd_url then
+            msg.error("No manifest URL found in JSON data.")
+            return
+        elseif not url_is_safe(mpd_url) then
+            return
+        end
+
+        streamurl = mpd_url
+
+        if reqfmts then
+            for _, track in pairs(reqfmts) do
+                max_bitrate = track.tbr > max_bitrate and
+                    track.tbr or max_bitrate
+            end
+        elseif json.tbr then
+            max_bitrate = json.tbr > max_bitrate and json.tbr or max_bitrate
+        end
 
     -- DASH/split tracks
-    if not (json["requested_formats"] == nil) then
-        for _, track in pairs(json.requested_formats) do
+    elseif reqfmts then
+        for _, track in pairs(reqfmts) do
             local edl_track = nil
             edl_track = edl_track_joined(track.fragments,
                 track.protocol, json.is_live,
                 track.fragment_base_url)
+            if not edl_track and not url_is_safe(track.url) then
+                return
+            end
             if track.acodec and track.acodec ~= "none" then
                 -- audio track
                 mp.commandv("audio-add",
@@ -217,6 +289,9 @@ local function add_single_video(json)
         edl_track = edl_track_joined(json.fragments, json.protocol,
             json.is_live, json.fragment_base_url)
 
+        if not edl_track and not url_is_safe(json.url) then
+            return
+        end
         -- normal video or single track
         streamurl = edl_track or json.url
         set_http_headers(json.http_headers)
@@ -231,6 +306,13 @@ local function add_single_video(json)
 
     mp.set_property("file-local-options/force-media-title", json.title)
 
+    -- set hls-bitrate for dash track selection
+    if max_bitrate > 0 and
+        not option_was_set("hls-bitrate") and
+        not option_was_set_locally("hls-bitrate") then
+        mp.set_property_native('file-local-options/hls-bitrate', max_bitrate*1000)
+    end
+
     -- add subtitles
     if not (json.requested_subtitles == nil) then
         for lang, sub_info in pairs(json.requested_subtitles) do
@@ -309,7 +391,8 @@ mp.add_hook("on_load", 10, function ()
 
         -- check for youtube-dl in mpv's config dir
         if not (ytdl.searched) then
-            local ytdl_mcd = mp.find_config_file("youtube-dl")
+            local exesuf = (package.config:sub(1,1) == '\\') and '.exe' or ''
+            local ytdl_mcd = mp.find_config_file("youtube-dl" .. exesuf)
             if not (ytdl_mcd == nil) then
                 msg.verbose("found youtube-dl at: " .. ytdl_mcd)
                 ytdl.path = ytdl_mcd
@@ -365,9 +448,15 @@ mp.add_hook("on_load", 10, function ()
         local es, json, result = exec(command)
 
         if (es < 0) or (json == nil) or (json == "") then
-            if not result.killed_by_us then
-                msg.warn("youtube-dl failed, trying to play URL directly ...")
+            local err = "youtube-dl failed: "
+            if result.error and result.error == "init" then
+                err = err .. "not found or not enough permissions"
+            elseif not result.killed_by_us then
+                err = err .. "unexpected error ocurred"
+            else
+                err = string.format("%s returned '%d'", err, es)
             end
+            msg.error(err)
             return
         end
 
@@ -396,18 +485,26 @@ mp.add_hook("on_load", 10, function ()
                 return
             end
 
+            local self_redirecting_url =
+                json.entries[1]["_type"] ~= "url_transparent" and
+                json.entries[1]["webpage_url"] and
+                json.entries[1]["webpage_url"] == json["webpage_url"]
+
 
             -- some funky guessing to detect multi-arc videos
-            if (not (json.entries[1]["_type"] == "url_transparent")) and
-                (not (json.entries[1]["webpage_url"] == nil)
-                and (json.entries[1]["webpage_url"] == json["webpage_url"]))
-                and not (json.entries[1].url == nil) then
+            if self_redirecting_url and #json.entries > 1
+                and json.entries[1].protocol == "m3u8_native"
+                and json.entries[1].url then
                 msg.verbose("multi-arc video detected, building EDL")
 
                 local playlist = edl_track_joined(json.entries)
 
                 msg.debug("EDL: " .. playlist)
 
+                if not playlist then
+                    return
+                end
+
                 -- can't change the http headers for each entry, so use the 1st
                 if json.entries[1] then
                     set_http_headers(json.entries[1].http_headers)
@@ -446,39 +543,43 @@ mp.add_hook("on_load", 10, function ()
                     end
                 end
 
-            elseif (not (json.entries[1]["_type"] == "url_transparent")) and
-                (not (json.entries[1]["webpage_url"] == nil)
-                and (json.entries[1]["webpage_url"] == json["webpage_url"]))
-                and (#json.entries == 1) then
-
+            elseif self_redirecting_url and #json.entries == 1 then
                 msg.verbose("Playlist with single entry detected.")
                 add_single_video(json.entries[1])
             else
-
-                local playlist = "#EXTM3U\n"
+                local playlist = {"#EXTM3U"}
                 for i, entry in pairs(json.entries) do
                     local site = entry.url
                     local title = entry.title
 
                     if not (title == nil) then
                         title = string.gsub(title, '%s+', ' ')
-                        playlist = playlist .. "#EXTINF:0," .. title .. "\n"
+                        table.insert(playlist, "#EXTINF:0," .. title)
                     end
 
-                    -- some extractors will still return the full info for
-                    -- all clips in the playlist and the URL will point
-                    -- directly to the file in that case, which we don't
-                    -- want so get the webpage URL instead, which is what
-                    -- we want
-                    if not (json.entries[1]["_type"] == "url_transparent")
-                        and not (entry["webpage_url"] == nil) then
+                    --[[ some extractors will still return the full info for
+                         all clips in the playlist and the URL will point
+                         directly to the file in that case, which we don't
+                         want so get the webpage URL instead, which is what
+                         we want, but only if we aren't going to trigger an
+                         infinite loop
+                    --]]
+                    if entry["webpage_url"] and not self_redirecting_url then
                         site = entry["webpage_url"]
                     end
 
-                    playlist = playlist .. "ytdl://" .. site .. "\n"
+                    -- links with only youtube id as returned by --flat-playlist
+                    if not site:find("://") then
+                        table.insert(playlist, "ytdl://" .. site)
+                    elseif url_is_safe(site) then
+                        table.insert(playlist, site)
+                    end
+
                 end
 
-                mp.set_property("stream-open-filename", "memory://" .. playlist)
+                if #playlist > 0 then
+                    mp.set_property("stream-open-filename", "memory://" .. table.concat(playlist, "\n"))
+                end
             end
 
         else -- probably a video
