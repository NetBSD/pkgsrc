$NetBSD: patch-youtube__dl_extractor_rai.py,v 1.1 2019/12/09 11:45:59 leot Exp $

[rai] Fix extraction for recent raiplay.it updates

- Introduce _BASE_URL in RaiBaseIE class so it could be reused as base for the
  several subextractors.
- Remove first test of RaiPlayIE, it is no longer available
- Adjust RaiPlayIE to recent raiplay.it updates, make it extension agnostic
  (passing possible `.json' URLs is now supported too) and update test
  info_dict.
- Adjust RaiPlayLiveIE to recent raiplay.it updates.  Passing it as
  `url_transparent' is no longer supported (there is no longer an accessible
  ContentItem)
- Adjust RaiPlayPlaylistIE to recent raiplay.it updates and instruct it about
  ContentSet-s.

This fix issue #22923, #22906 and supersedes #23006.

Shared upstream via:

 https://github.com/ytdl-org/youtube-dl/pull/23040

--- youtube_dl/extractor/rai.py.orig
+++ youtube_dl/extractor/rai.py
@@ -17,7 +17,6 @@
     parse_duration,
     strip_or_none,
     try_get,
-    unescapeHTML,
     unified_strdate,
     unified_timestamp,
     update_url_query,
@@ -30,6 +29,7 @@ class RaiBaseIE(InfoExtractor):
     _UUID_RE = r'[\da-f]{8}-[\da-f]{4}-[\da-f]{4}-[\da-f]{4}-[\da-f]{12}'
     _GEO_COUNTRIES = ['IT']
     _GEO_BYPASS = False
+    _BASE_URL = 'https://www.raiplay.it'
 
     def _extract_relinker_info(self, relinker_url, video_id):
         if not re.match(r'https?://', relinker_url):
@@ -122,41 +122,19 @@ def _extract_subtitles(url, subtitle_url):
 
 
 class RaiPlayIE(RaiBaseIE):
-    _VALID_URL = r'(?P<url>https?://(?:www\.)?raiplay\.it/.+?-(?P<id>%s)\.html)' % RaiBaseIE._UUID_RE
+    _VALID_URL = r'(?P<url>(?P<base>https?://(?:www\.)?raiplay\.it/.+?-)(?P<id>%s)(?P<ext>\.(?:html|json)))' % RaiBaseIE._UUID_RE
     _TESTS = [{
-        'url': 'http://www.raiplay.it/video/2016/10/La-Casa-Bianca-e06118bb-59a9-4636-b914-498e4cfd2c66.html?source=twitter',
-        'md5': '340aa3b7afb54bfd14a8c11786450d76',
-        'info_dict': {
-            'id': 'e06118bb-59a9-4636-b914-498e4cfd2c66',
-            'ext': 'mp4',
-            'title': 'La Casa Bianca',
-            'alt_title': 'S2016 - Puntata del 23/10/2016',
-            'description': 'md5:a09d45890850458077d1f68bb036e0a5',
-            'thumbnail': r're:^https?://.*\.jpg$',
-            'uploader': 'Rai 3',
-            'creator': 'Rai 3',
-            'duration': 3278,
-            'timestamp': 1477764300,
-            'upload_date': '20161029',
-            'series': 'La Casa Bianca',
-            'season': '2016',
-        },
-    }, {
         'url': 'http://www.raiplay.it/video/2014/04/Report-del-07042014-cb27157f-9dd0-4aee-b788-b1f67643a391.html',
         'md5': '8970abf8caf8aef4696e7b1f2adfc696',
         'info_dict': {
             'id': 'cb27157f-9dd0-4aee-b788-b1f67643a391',
             'ext': 'mp4',
             'title': 'Report del 07/04/2014',
-            'alt_title': 'S2013/14 - Puntata del 07/04/2014',
-            'description': 'md5:f27c544694cacb46a078db84ec35d2d9',
+            'alt_title': 'St 2013/14 - Espresso nel caffè - 07/04/2014 ',
+            'description': 'md5:d730c168a58f4bb35600fc2f881ec04e',
             'thumbnail': r're:^https?://.*\.jpg$',
-            'uploader': 'Rai 5',
-            'creator': 'Rai 5',
+            'uploader': 'Rai Gulp',
             'duration': 6160,
-            'series': 'Report',
-            'season_number': 5,
-            'season': '2013/14',
         },
         'params': {
             'skip_download': True,
@@ -168,16 +146,15 @@ class RaiPlayIE(RaiBaseIE):
 
     def _real_extract(self, url):
         mobj = re.match(self._VALID_URL, url)
-        url, video_id = mobj.group('url', 'id')
+        url, base, video_id, ext = mobj.group('url', 'base', 'id', 'ext')
 
         media = self._download_json(
-            '%s?json' % url, video_id, 'Downloading video JSON')
+            '%s%s.json' % (base, video_id), video_id, 'Downloading video JSON')
 
         title = media['name']
-
         video = media['video']
 
-        relinker_info = self._extract_relinker_info(video['contentUrl'], video_id)
+        relinker_info = self._extract_relinker_info(video['content_url'], video_id)
         self._sort_formats(relinker_info['formats'])
 
         thumbnails = []
@@ -185,7 +162,7 @@ def _real_extract(self, url):
             for _, value in media.get('images').items():
                 if value:
                     thumbnails.append({
-                        'url': value.replace('[RESOLUTION]', '600x400')
+                        'url': urljoin(RaiBaseIE._BASE_URL, value.replace('[RESOLUTION]', '600x400'))
                     })
 
         timestamp = unified_timestamp(try_get(
@@ -225,7 +202,7 @@ class RaiPlayLiveIE(RaiBaseIE):
             'display_id': 'rainews24',
             'ext': 'mp4',
             'title': 're:^Diretta di Rai News 24 [0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}$',
-            'description': 'md5:6eca31500550f9376819f174e5644754',
+            'description': 'md5:4d00bcf6dc98b27c6ec480de329d1497',
             'uploader': 'Rai News 24',
             'creator': 'Rai News 24',
             'is_live': True,
@@ -238,20 +215,32 @@ class RaiPlayLiveIE(RaiBaseIE):
     def _real_extract(self, url):
         display_id = self._match_id(url)
 
-        webpage = self._download_webpage(url, display_id)
+        media = self._download_json(
+            '%s.json' % urljoin(RaiBaseIE._BASE_URL, 'dirette/' + display_id),
+            display_id, 'Downloading channel JSON')
 
-        video_id = self._search_regex(
-            r'data-uniquename=["\']ContentItem-(%s)' % RaiBaseIE._UUID_RE,
-            webpage, 'content id')
+        title = media['name']
+        video = media['video']
+        video_id = media['id'].replace('ContentItem-', '')
+
+        relinker_info = self._extract_relinker_info(video['content_url'], video_id)
+        self._sort_formats(relinker_info['formats'])
 
-        return {
-            '_type': 'url_transparent',
-            'ie_key': RaiPlayIE.ie_key(),
-            'url': 'http://www.raiplay.it/dirette/ContentItem-%s.html' % video_id,
+        info = {
             'id': video_id,
             'display_id': display_id,
+            'title': self._live_title(title) if relinker_info.get(
+                'is_live') else title,
+            'alt_title': media.get('subtitle'),
+            'description': media.get('description'),
+            'uploader': strip_or_none(media.get('channel')),
+            'creator': strip_or_none(media.get('editor')),
+            'duration': parse_duration(video.get('duration')),
         }
 
+        info.update(relinker_info)
+        return info
+
 
 class RaiPlayPlaylistIE(InfoExtractor):
     _VALID_URL = r'https?://(?:www\.)?raiplay\.it/programmi/(?P<id>[^/?#&]+)'
@@ -260,7 +249,7 @@ class RaiPlayPlaylistIE(InfoExtractor):
         'info_dict': {
             'id': 'nondirloalmiocapo',
             'title': 'Non dirlo al mio capo',
-            'description': 'md5:9f3d603b2947c1c7abb098f3b14fac86',
+            'description': 'md5:98ab6b98f7f44c2843fd7d6f045f153b',
         },
         'playlist_mincount': 12,
     }]
@@ -268,21 +257,25 @@ class RaiPlayPlaylistIE(InfoExtractor):
     def _real_extract(self, url):
         playlist_id = self._match_id(url)
 
-        webpage = self._download_webpage(url, playlist_id)
+        media = self._download_json(
+            '%s.json' % urljoin(RaiBaseIE._BASE_URL, 'programmi/' + playlist_id),
+            playlist_id, 'Downloading program JSON')
+
+        title = media['name']
+        description = media['program_info']['description']
 
-        title = self._html_search_meta(
-            ('programma', 'nomeProgramma'), webpage, 'title')
-        description = unescapeHTML(self._html_search_meta(
-            ('description', 'og:description'), webpage, 'description'))
+        content_sets = [s['id'] for b in media['blocks'] for s in b['sets']]
 
         entries = []
-        for mobj in re.finditer(
-                r'<a\b[^>]+\bhref=(["\'])(?P<path>/raiplay/video/.+?)\1',
-                webpage):
-            video_url = urljoin(url, mobj.group('path'))
-            entries.append(self.url_result(
-                video_url, ie=RaiPlayIE.ie_key(),
-                video_id=RaiPlayIE._match_id(video_url)))
+        for cs in content_sets:
+            medias = self._download_json(
+                '%s/%s.json' % (urljoin(RaiBaseIE._BASE_URL, 'programmi/' + playlist_id), cs),
+                cs, 'Downloading content set JSON')
+            for m in medias['items']:
+                video_url = urljoin(url, m['path_id'])
+                entries.append(self.url_result(
+                    video_url, ie=RaiPlayIE.ie_key(),
+                    video_id=RaiPlayIE._match_id(video_url)))
 
         return self.playlist_result(entries, playlist_id, title, description)
 
