$NetBSD: patch-youtube__dl_extractor_bandcamp.py,v 1.1 2020/11/01 10:58:24 leot Exp $

[bandcamp] Update to handle HTML quoted data

Adjust the extractor to handle JSON data-* attributes by introducing a
_json_data_extract() method to handle them (and existing existing
patterns in the code).

Based on Gilles Pietri #26684.

--- youtube_dl/extractor/bandcamp.py.orig	2020-09-20 05:29:46.000000000 +0000
+++ youtube_dl/extractor/bandcamp.py
@@ -35,12 +35,15 @@ class BandcampIE(InfoExtractor):
             'ext': 'mp3',
             'title': "youtube-dl  \"'/\\\u00e4\u21ad - youtube-dl test song \"'/\\\u00e4\u21ad",
             'duration': 9.8485,
+            'uploader': "youtube-dl  \"'/\\\u00e4\u21ad",
+            'timestamp': 1354224127,
+            'upload_date': '20121129',
         },
         '_skip': 'There is a limit of 200 free downloads / month for the test song'
     }, {
         # free download
         'url': 'http://benprunty.bandcamp.com/track/lanius-battle',
-        'md5': '853e35bf34aa1d6fe2615ae612564b36',
+        'md5': '149170678c0a81a009c69566bf42920a',
         'info_dict': {
             'id': '2650410135',
             'ext': 'aiff',
@@ -79,6 +82,14 @@ class BandcampIE(InfoExtractor):
         },
     }]
 
+    def _json_data_extract(self, data_key, video_id, webpage):
+        return self._parse_json(
+            self._search_regex(
+                r'data-' + data_key + r'=(["\'])(?P<data>{.+?})\1',
+                webpage, 'JSON data {data_key}'.format(data_key=data_key),
+                group='data', default=None),
+            video_id, transform_source=unescapeHTML)
+
     def _real_extract(self, url):
         mobj = re.match(self._VALID_URL, url)
         title = mobj.group('title')
@@ -91,10 +102,9 @@ class BandcampIE(InfoExtractor):
         duration = None
 
         formats = []
-        track_info = self._parse_json(
-            self._search_regex(
-                r'trackinfo\s*:\s*\[\s*({.+?})\s*\]\s*,\s*?\n',
-                webpage, 'track info', default='{}'), title)
+        tralbum_data = self._json_data_extract('tralbum', title, webpage)
+        embed_data = self._json_data_extract('embed', title, webpage)
+        track_info = tralbum_data['trackinfo'][0]
         if track_info:
             file_ = track_info.get('file')
             if isinstance(file_, dict):
@@ -110,38 +120,28 @@ class BandcampIE(InfoExtractor):
                         'acodec': ext,
                         'abr': int_or_none(abr_str),
                     })
-            track = track_info.get('title')
             track_id = str_or_none(track_info.get('track_id') or track_info.get('id'))
             track_number = int_or_none(track_info.get('track_num'))
             duration = float_or_none(track_info.get('duration'))
 
         def extract(key):
-            return self._search_regex(
-                r'\b%s\s*["\']?\s*:\s*(["\'])(?P<value>(?:(?!\1).)+)\1' % key,
-                webpage, key, default=None, group='value')
+            for data in tralbum_data['current'], embed_data, tralbum_data:
+                if key in data and data[key]:
+                    return data[key]
 
         artist = extract('artist')
+        track = extract('title')
         album = extract('album_title')
         timestamp = unified_timestamp(
             extract('publish_date') or extract('album_publish_date'))
         release_date = unified_strdate(extract('album_release_date'))
 
-        download_link = self._search_regex(
-            r'freeDownloadPage\s*:\s*(["\'])(?P<url>(?:(?!\1).)+)\1', webpage,
-            'download link', default=None, group='url')
+        download_link = tralbum_data['freeDownloadPage']
         if download_link:
-            track_id = self._search_regex(
-                r'(?ms)var TralbumData = .*?[{,]\s*id: (?P<id>\d+),?$',
-                webpage, 'track id')
-
             download_webpage = self._download_webpage(
                 download_link, track_id, 'Downloading free downloads page')
 
-            blob = self._parse_json(
-                self._search_regex(
-                    r'data-blob=(["\'])(?P<blob>{.+?})\1', download_webpage,
-                    'blob', group='blob'),
-                track_id, transform_source=unescapeHTML)
+            blob = self._json_data_extract('blob', track_id, download_webpage)
 
             info = try_get(
                 blob, (lambda x: x['digital_items'][0],
@@ -218,7 +218,7 @@ class BandcampIE(InfoExtractor):
         }
 
 
-class BandcampAlbumIE(InfoExtractor):
+class BandcampAlbumIE(BandcampIE):
     IE_NAME = 'Bandcamp:album'
     _VALID_URL = r'https?://(?:(?P<subdomain>[^.]+)\.)?bandcamp\.com(?:/album/(?P<album_id>[^/?#&]+))?'
 
@@ -299,26 +299,23 @@ class BandcampAlbumIE(InfoExtractor):
         album_id = mobj.group('album_id')
         playlist_id = album_id or uploader_id
         webpage = self._download_webpage(url, playlist_id)
-        track_elements = re.findall(
-            r'(?s)<div[^>]*>(.*?<a[^>]+href="([^"]+?)"[^>]+itemprop="url"[^>]*>.*?)</div>', webpage)
+
+        tralbum_data = self._json_data_extract('tralbum', album_id, webpage)
+        embed_data = self._json_data_extract('embed', album_id, webpage)
+        title = embed_data.get('album_title')
+
+        track_elements = tralbum_data['trackinfo']
         if not track_elements:
             raise ExtractorError('The page doesn\'t contain any tracks')
         # Only tracks with duration info have songs
         entries = [
             self.url_result(
-                compat_urlparse.urljoin(url, t_path),
+                compat_urlparse.urljoin(url, t['title_link']),
                 ie=BandcampIE.ie_key(),
-                video_title=self._search_regex(
-                    r'<span\b[^>]+\bitemprop=["\']name["\'][^>]*>([^<]+)',
-                    elem_content, 'track title', fatal=False))
-            for elem_content, t_path in track_elements
-            if self._html_search_meta('duration', elem_content, default=None)]
-
-        title = self._html_search_regex(
-            r'album_title\s*:\s*"((?:\\.|[^"\\])+?)"',
-            webpage, 'title', fatal=False)
-        if title:
-            title = title.replace(r'\"', '"')
+                video_title=t['title'])
+            for t in track_elements
+            if t['duration']]
+
         return {
             '_type': 'playlist',
             'uploader_id': uploader_id,
@@ -328,22 +325,21 @@ class BandcampAlbumIE(InfoExtractor):
         }
 
 
-class BandcampWeeklyIE(InfoExtractor):
+class BandcampWeeklyIE(BandcampIE):
     IE_NAME = 'Bandcamp:weekly'
     _VALID_URL = r'https?://(?:www\.)?bandcamp\.com/?\?(?:.*?&)?show=(?P<id>\d+)'
     _TESTS = [{
         'url': 'https://bandcamp.com/?show=224',
-        'md5': 'b00df799c733cf7e0c567ed187dea0fd',
+        'md5': '61acc9a002bed93986b91168aa3ab433',
         'info_dict': {
             'id': '224',
-            'ext': 'opus',
+            'ext': 'mp3',
             'title': 'BC Weekly April 4th 2017 - Magic Moments',
             'description': 'md5:5d48150916e8e02d030623a48512c874',
             'duration': 5829.77,
             'release_date': '20170404',
             'series': 'Bandcamp Weekly',
             'episode': 'Magic Moments',
-            'episode_number': 208,
             'episode_id': '224',
         }
     }, {
@@ -355,13 +351,13 @@ class BandcampWeeklyIE(InfoExtractor):
         video_id = self._match_id(url)
         webpage = self._download_webpage(url, video_id)
 
-        blob = self._parse_json(
-            self._search_regex(
-                r'data-blob=(["\'])(?P<blob>{.+?})\1', webpage,
-                'blob', group='blob'),
-            video_id, transform_source=unescapeHTML)
+        blob = self._json_data_extract('blob', video_id, webpage)
 
-        show = blob['bcw_show']
+        show = None
+        for bd in blob['bcw_data']:
+            if blob['bcw_data'][bd].get('expanded'):
+                show = blob['bcw_data'][bd]
+                break
 
         # This is desired because any invalid show id redirects to `bandcamp.com`
         # which happens to expose the latest Bandcamp Weekly episode.
@@ -390,18 +386,6 @@ class BandcampWeeklyIE(InfoExtractor):
         if subtitle:
             title += ' - %s' % subtitle
 
-        episode_number = None
-        seq = blob.get('bcw_seq')
-
-        if seq and isinstance(seq, list):
-            try:
-                episode_number = next(
-                    int_or_none(e.get('episode_number'))
-                    for e in seq
-                    if isinstance(e, dict) and int_or_none(e.get('id')) == show_id)
-            except StopIteration:
-                pass
-
         return {
             'id': video_id,
             'title': title,
@@ -411,7 +395,6 @@ class BandcampWeeklyIE(InfoExtractor):
             'release_date': unified_strdate(show.get('published_date')),
             'series': 'Bandcamp Weekly',
             'episode': show.get('subtitle'),
-            'episode_number': episode_number,
             'episode_id': compat_str(video_id),
             'formats': formats
         }
