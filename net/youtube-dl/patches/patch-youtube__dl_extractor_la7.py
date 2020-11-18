$NetBSD: patch-youtube__dl_extractor_la7.py,v 1.3 2020/11/18 17:35:15 leot Exp $

[la7] Fix extraction (closes #23323)

Parsing `videoParams' or `videoLa7' JavaScript snippets as JSON is getting too
hard for js_to_json.  Just extract the `vid' from there and use _search_og_*
for all other data.

Remove the 2nd test: unfortunately the page are removed after a couple of
days/weeks.

Thanks to Elia Geretto for spotting and suggesting several problems with the
tests!

Closes #23323.

Shared upstream via:

 https://github.com/ytdl-org/youtube-dl/pull/23641

--- youtube_dl/extractor/la7.py.orig	2020-11-16 21:04:10.000000000 +0000
+++ youtube_dl/extractor/la7.py
@@ -3,7 +3,6 @@ from __future__ import unicode_literals
 
 from .common import InfoExtractor
 from ..utils import (
-    js_to_json,
     smuggle_url,
 )
 
@@ -23,22 +22,13 @@ class LA7IE(InfoExtractor):
             'id': '0_42j6wd36',
             'ext': 'mp4',
             'title': 'Inc.Cool8',
-            'description': 'Benvenuti nell\'incredibile mondo della INC. COOL. 8. dove “INC.” sta per “Incorporated” “COOL” sta per “fashion” ed Eight sta per il gesto  atletico',
+            'description': 'Benvenuti nell\'incredibile mondo della INC. COOL. 8. dove “INC.” sta per “Incorporated” “COOL” sta per “fashion” ed Eight sta per il gesto atletico',
             'thumbnail': 're:^https?://.*',
             'uploader_id': 'kdla7pillole@iltrovatore.it',
             'timestamp': 1443814869,
             'upload_date': '20151002',
         },
     }, {
-        # 'src' is a dictionary
-        'url': 'http://tg.la7.it/repliche-tgla7?id=189080',
-        'md5': '6b0d8888d286e39870208dfeceaf456b',
-        'info_dict': {
-            'id': '189080',
-            'ext': 'mp4',
-            'title': 'TG LA7',
-        },
-    }, {
         'url': 'http://www.la7.it/omnibus/rivedila7/omnibus-news-02-07-2016-189077',
         'only_matching': True,
     }]
@@ -48,20 +38,19 @@ class LA7IE(InfoExtractor):
 
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
