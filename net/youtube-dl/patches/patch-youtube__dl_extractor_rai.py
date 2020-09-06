$NetBSD: patch-youtube__dl_extractor_rai.py,v 1.2 2020/09/06 09:54:34 leot Exp $

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
- Update a RaiIE test and remove two tests that are no longer availables

This fix issue #22923, #22906 and supersedes #23006.

Shared upstream via:

 https://github.com/ytdl-org/youtube-dl/pull/23040

--- youtube_dl/extractor/rai.py.orig
+++ youtube_dl/extractor/rai.py
@@ -1,3 +1,4 @@
+# coding: utf-8
 from __future__ import unicode_literals
 
 import re
@@ -17,7 +18,6 @@
     parse_duration,
     strip_or_none,
     try_get,
-    unescapeHTML,
     unified_strdate,
     unified_timestamp,
     update_url_query,
@@ -30,6 +30,7 @@ class RaiBaseIE(InfoExtractor):
     _UUID_RE = r'[\da-f]{8}-[\da-f]{4}-[\da-f]{4}-[\da-f]{4}-[\da-f]{12}'
     _GEO_COUNTRIES = ['IT']
     _GEO_BYPASS = False
+    _BASE_URL = 'https://www.raiplay.it'
 
     def _extract_relinker_info(self, relinker_url, video_id):
         if not re.match(r'https?://', relinker_url):
@@ -122,41 +123,19 @@ def _extract_subtitles(url, subtitle_url):
 
 
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
@@ -168,16 +147,15 @@ class RaiPlayIE(RaiBaseIE):
 
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
@@ -185,7 +163,7 @@ def _real_extract(self, url):
             for _, value in media.get('images').items():
                 if value:
                     thumbnails.append({
-                        'url': value.replace('[RESOLUTION]', '600x400')
+                        'url': urljoin(RaiBaseIE._BASE_URL, value.replace('[RESOLUTION]', '600x400'))
                     })
 
         timestamp = unified_timestamp(try_get(
@@ -225,7 +203,7 @@ class RaiPlayLiveIE(RaiBaseIE):
             'display_id': 'rainews24',
             'ext': 'mp4',
             'title': 're:^Diretta di Rai News 24 [0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}$',
-            'description': 'md5:6eca31500550f9376819f174e5644754',
+            'description': 'md5:4d00bcf6dc98b27c6ec480de329d1497',
             'uploader': 'Rai News 24',
             'creator': 'Rai News 24',
             'is_live': True,
@@ -238,20 +216,32 @@ class RaiPlayLiveIE(RaiBaseIE):
     def _real_extract(self, url):
         display_id = self._match_id(url)
 
-        webpage = self._download_webpage(url, display_id)
+        media = self._download_json(
+            '%s.json' % urljoin(RaiBaseIE._BASE_URL, 'dirette/' + display_id),
+            display_id, 'Downloading channel JSON')
+
+        title = media['name']
+        video = media['video']
+        video_id = media['id'].replace('ContentItem-', '')
 
-        video_id = self._search_regex(
-            r'data-uniquename=["\']ContentItem-(%s)' % RaiBaseIE._UUID_RE,
-            webpage, 'content id')
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
@@ -260,7 +250,7 @@ class RaiPlayPlaylistIE(InfoExtractor):
         'info_dict': {
             'id': 'nondirloalmiocapo',
             'title': 'Non dirlo al mio capo',
-            'description': 'md5:9f3d603b2947c1c7abb098f3b14fac86',
+            'description': 'md5:98ab6b98f7f44c2843fd7d6f045f153b',
         },
         'playlist_mincount': 12,
     }]
@@ -268,21 +258,25 @@ class RaiPlayPlaylistIE(InfoExtractor):
     def _real_extract(self, url):
         playlist_id = self._match_id(url)
 
-        webpage = self._download_webpage(url, playlist_id)
+        media = self._download_json(
+            '%s.json' % urljoin(RaiBaseIE._BASE_URL, 'programmi/' + playlist_id),
+            playlist_id, 'Downloading program JSON')
 
-        title = self._html_search_meta(
-            ('programma', 'nomeProgramma'), webpage, 'title')
-        description = unescapeHTML(self._html_search_meta(
-            ('description', 'og:description'), webpage, 'description'))
+        title = media['name']
+        description = media['program_info']['description']
+
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
 
@@ -316,7 +310,7 @@ class RaiIE(RaiBaseIE):
     }, {
         # with ContentItem in og:url
         'url': 'http://www.rai.it/dl/RaiTV/programmi/media/ContentItem-efb17665-691c-45d5-a60c-5301333cbb0c.html',
-        'md5': '11959b4e44fa74de47011b5799490adf',
+        'md5': '6865dd00cf0bbf5772fdd89d59bd768a',
         'info_dict': {
             'id': 'efb17665-691c-45d5-a60c-5301333cbb0c',
             'ext': 'mp4',
@@ -326,18 +320,6 @@ class RaiIE(RaiBaseIE):
             'duration': 2214,
             'upload_date': '20161103',
         }
-    }, {
-        # drawMediaRaiTV(...)
-        'url': 'http://www.report.rai.it/dl/Report/puntata/ContentItem-0c7a664b-d0f4-4b2c-8835-3f82e46f433e.html',
-        'md5': '2dd727e61114e1ee9c47f0da6914e178',
-        'info_dict': {
-            'id': '59d69d28-6bb6-409d-a4b5-ed44096560af',
-            'ext': 'mp4',
-            'title': 'Il pacco',
-            'description': 'md5:4b1afae1364115ce5d78ed83cd2e5b3a',
-            'thumbnail': r're:^https?://.*\.jpg$',
-            'upload_date': '20141221',
-        },
     }, {
         # initEdizione('ContentItem-...'
         'url': 'http://www.tg1.rai.it/dl/tg1/2010/edizioni/ContentSet-9b6e0cba-4bef-4aef-8cf0-9f7f665b7dfb-tg1.html?item=undefined',
@@ -349,17 +331,6 @@ class RaiIE(RaiBaseIE):
             'upload_date': '20170401',
         },
         'skip': 'Changes daily',
-    }, {
-        # HDS live stream with only relinker URL
-        'url': 'http://www.rai.tv/dl/RaiTV/dirette/PublishingBlock-1912dbbf-3f96-44c3-b4cf-523681fbacbc.html?channel=EuroNews',
-        'info_dict': {
-            'id': '1912dbbf-3f96-44c3-b4cf-523681fbacbc',
-            'ext': 'flv',
-            'title': 'EuroNews',
-        },
-        'params': {
-            'skip_download': True,
-        },
     }, {
         # HLS live stream with ContentItem in og:url
         'url': 'http://www.rainews.it/dl/rainews/live/ContentItem-3156f2f2-dc70-4953-8e2f-70d7489d4ce9.html',
