$NetBSD: patch-youtube__dl_extractor_la7.py,v 1.1.2.2 2020/01/27 11:04:38 bsiegert Exp $

[la7] Fix extraction

Parsing `videoParams' or `videoLa7' JavaScript snippets as JSON is getting too
for js_to_json.  Just extract the `vid' from there and use _search_og_* for all
other data.

Update 2nd test with an existent video.

Closes #23323.

Shared upstream via:

 <https://github.com/ytdl-org/youtube-dl/pull/23641>

--- youtube_dl/extractor/la7.py.orig
+++ youtube_dl/extractor/la7.py
@@ -3,7 +3,6 @@ from __future__ import unicode_literals
 
 from .common import InfoExtractor
 from ..utils import (
-    js_to_json,
     smuggle_url,
 )
 
@@ -31,12 +30,16 @@ class LA7IE(InfoExtractor):
         },
     }, {
         # 'src' is a dictionary
-        'url': 'http://tg.la7.it/repliche-tgla7?id=189080',
-        'md5': '6b0d8888d286e39870208dfeceaf456b',
+        'url': 'http://tg.la7.it/repliche-tgla7?id=300465',
+        'md5': '9440057f4531005c426421487770b756',
         'info_dict': {
-            'id': '189080',
+            'id': '0_i2fn53i6',
             'ext': 'mp4',
-            'title': 'TG LA7',
+            'title': 'Repliche Tgla7',
+            'description': 'Repliche Tgla7',
+            'uploader_id': 'kdla7pillole@iltrovatore.it',
+            'timestamp': 1578231030,
+            'upload_date': '20200105',
         },
     }, {
         'url': 'http://www.la7.it/omnibus/rivedila7/omnibus-news-02-07-2016-189077',
@@ -48,20 +51,19 @@ class LA7IE(InfoExtractor):
 
         webpage = self._download_webpage(url, video_id)
 
-        player_data = self._parse_json(
-            self._search_regex(
-                [r'(?s)videoParams\s*=\s*({.+?});', r'videoLa7\(({[^;]+})\);'],
-                webpage, 'player data'),
-            video_id, transform_source=js_to_json)
+        player_data = self._search_regex(
+            [r'(?s)videoParams\s*=\s*({.+?});', r'videoLa7\(({[^;]+})\);'],
+            webpage, 'player data')
+        vid = self._search_regex(r'vid\s*:\s*"(.+?)",', player_data, 'vid')
 
         return {
             '_type': 'url_transparent',
-            'url': smuggle_url('kaltura:103:%s' % player_data['vid'], {
+            'url': smuggle_url('kaltura:103:%s' % vid, {
                 'service_url': 'http://nkdam.iltrovatore.it',
             }),
             'id': video_id,
-            'title': player_data['title'],
+            'title': self._og_search_title(webpage, default=None),
             'description': self._og_search_description(webpage, default=None),
-            'thumbnail': player_data.get('poster'),
+            'thumbnail': self._og_search_thumbnail(webpage, default=None),
             'ie_key': 'Kaltura',
         }
