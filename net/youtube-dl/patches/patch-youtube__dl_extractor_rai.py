$NetBSD: patch-youtube__dl_extractor_rai.py,v 1.3 2020/11/18 17:35:15 leot Exp $

[rai] Fix extraction for recent raiplay.it updates

- Introduce _BASE_URL in RaiBaseIE class so it could be reused as base for the
  several subextractors.
- Remove first test of RaiPlayIE: it is no longer available
- Make RaiPlayIE extension-agnostic (passing possible `.json' URLs is now
  supported too)
- Adjust RaiPlayLiveIE to recent raiplay.it updates.  Passing it as
  `url_transparent' is no longer supported (there is no longer an accessible
  ContentItem)
- Adjust RaiPlayPlaylistIE to recent raiplay.it updates and instruct it about
  ContentSet-s.
- Update a RaiIE test and remove two tests that are no longer availables

This fix issue #22923, #22906 and supersedes #23006 and #23040.

Shared upstream via:

 https://github.com/ytdl-org/youtube-dl/pull/27077

--- youtube_dl/extractor/rai.py.orig	2020-11-16 21:04:10.000000000 +0000
+++ youtube_dl/extractor/rai.py
@@ -17,7 +17,6 @@ from ..utils import (
     int_or_none,
     parse_duration,
     strip_or_none,
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
@@ -122,27 +122,8 @@ class RaiBaseIE(InfoExtractor):
 
 
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
-        'skip': 'This content is not available',
-    }, {
         'url': 'http://www.raiplay.it/video/2014/04/Report-del-07042014-cb27157f-9dd0-4aee-b788-b1f67643a391.html',
         'md5': '8970abf8caf8aef4696e7b1f2adfc696',
         'info_dict': {
@@ -166,10 +147,11 @@ class RaiPlayIE(RaiBaseIE):
     }]
 
     def _real_extract(self, url):
-        url, video_id = re.match(self._VALID_URL, url).groups()
+        mobj = re.match(self._VALID_URL, url)
+        url, base, video_id, ext = mobj.group('url', 'base', 'id', 'ext')
 
         media = self._download_json(
-            url.replace('.html', '.json'), video_id, 'Downloading video JSON')
+            '%s%s.json' % (base, video_id), video_id, 'Downloading video JSON')
 
         title = media['name']
 
@@ -227,7 +209,7 @@ class RaiPlayLiveIE(RaiBaseIE):
             'display_id': 'rainews24',
             'ext': 'mp4',
             'title': 're:^Diretta di Rai News 24 [0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}$',
-            'description': 'md5:6eca31500550f9376819f174e5644754',
+            'description': 'md5:4d00bcf6dc98b27c6ec480de329d1497',
             'uploader': 'Rai News 24',
             'creator': 'Rai News 24',
             'is_live': True,
@@ -240,20 +222,32 @@ class RaiPlayLiveIE(RaiBaseIE):
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
+
+        relinker_info = self._extract_relinker_info(video['content_url'], video_id)
+        self._sort_formats(relinker_info['formats'])
 
-        video_id = self._search_regex(
-            r'data-uniquename=["\']ContentItem-(%s)' % RaiBaseIE._UUID_RE,
-            webpage, 'content id')
-
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
@@ -262,7 +256,7 @@ class RaiPlayPlaylistIE(InfoExtractor):
         'info_dict': {
             'id': 'nondirloalmiocapo',
             'title': 'Non dirlo al mio capo',
-            'description': 'md5:9f3d603b2947c1c7abb098f3b14fac86',
+            'description': 'md5:98ab6b98f7f44c2843fd7d6f045f153b',
         },
         'playlist_mincount': 12,
     }]
@@ -270,21 +264,25 @@ class RaiPlayPlaylistIE(InfoExtractor):
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
 
@@ -330,19 +328,6 @@ class RaiIE(RaiBaseIE):
             'upload_date': '20161103',
         }
     }, {
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
-        'skip': 'This content is not available',
-    }, {
         # initEdizione('ContentItem-...'
         'url': 'http://www.tg1.rai.it/dl/tg1/2010/edizioni/ContentSet-9b6e0cba-4bef-4aef-8cf0-9f7f665b7dfb-tg1.html?item=undefined',
         'info_dict': {
@@ -354,18 +339,6 @@ class RaiIE(RaiBaseIE):
         },
         'skip': 'Changes daily',
     }, {
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
-        'skip': 'This content is available only in Italy',
-    }, {
         # HLS live stream with ContentItem in og:url
         'url': 'http://www.rainews.it/dl/rainews/live/ContentItem-3156f2f2-dc70-4953-8e2f-70d7489d4ce9.html',
         'info_dict': {
