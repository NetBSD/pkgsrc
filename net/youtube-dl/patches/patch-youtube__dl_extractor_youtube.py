$NetBSD: patch-youtube__dl_extractor_youtube.py,v 1.1 2020/11/01 12:14:48 leot Exp $

Update JS player URL to current one.

Via:

 https://github.com/blackjack4494/yt-dlc/pull/35

--- youtube_dl/extractor/youtube.py.orig	2020-09-20 05:29:46.000000000 +0000
+++ youtube_dl/extractor/youtube.py
@@ -2086,7 +2086,7 @@ class YoutubeIE(YoutubeBaseInfoExtractor
 
                 if cipher:
                     if 's' in url_data or self._downloader.params.get('youtube_include_dash_manifest', True):
-                        ASSETS_RE = r'"assets":.+?"js":\s*("[^"]+")'
+                        ASSETS_RE = r'(?:"assets":.+?"js":\s*("[^"]+"))|(?:"jsUrl":\s*("[^"]+"))'
                         jsplayer_url_json = self._search_regex(
                             ASSETS_RE,
                             embed_webpage if age_gate else video_webpage,
