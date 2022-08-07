$NetBSD: patch-yt__dlp_extractor_arte.py,v 1.1 2022/08/07 06:51:25 wiz Exp $

Fix arte support.
https://github.com/yt-dlp/yt-dlp/pull/3302

--- yt_dlp/extractor/arte.py.orig	2022-07-18 00:04:11.000000000 +0000
+++ yt_dlp/extractor/arte.py
@@ -1,185 +1,190 @@
 import re
 
 from .common import InfoExtractor
-from ..compat import (
-    compat_str,
-)
 from ..utils import (
     ExtractorError,
+    GeoRestrictedError,
     int_or_none,
+    parse_iso8601,
     parse_qs,
-    qualities,
     strip_or_none,
-    try_get,
-    unified_strdate,
+    traverse_obj,
     url_or_none,
 )
 
 
 class ArteTVBaseIE(InfoExtractor):
     _ARTE_LANGUAGES = 'fr|de|en|es|it|pl'
-    _API_BASE = 'https://api.arte.tv/api/player/v1'
+    _API_BASE = 'https://api.arte.tv/api/player/v2'
 
 
 class ArteTVIE(ArteTVBaseIE):
     _VALID_URL = r'''(?x)
-                    https?://
+                    (?:https?://
                         (?:
                             (?:www\.)?arte\.tv/(?P<lang>%(langs)s)/videos|
                             api\.arte\.tv/api/player/v\d+/config/(?P<lang_2>%(langs)s)
                         )
-                        /(?P<id>\d{6}-\d{3}-[AF])
+                    |arte://program)
+                        /(?P<id>\d{6}-\d{3}-[AF]|LIVE)
                     ''' % {'langs': ArteTVBaseIE._ARTE_LANGUAGES}
     _TESTS = [{
         'url': 'https://www.arte.tv/en/videos/088501-000-A/mexico-stealing-petrol-to-survive/',
+        'only_matching': True,
+    }, {
+        'url': 'https://www.arte.tv/pl/videos/100103-000-A/usa-dyskryminacja-na-porodowce/',
         'info_dict': {
-            'id': '088501-000-A',
+            'id': '100103-000-A',
+            'title': 'USA: Dyskryminacja na porodówce',
+            'description': 'md5:242017b7cce59ffae340a54baefcafb1',
+            'alt_title': 'ARTE Reportage',
+            'upload_date': '20201103',
+            'duration': 554,
+            'thumbnail': r're:https://api-cdn\.arte\.tv/.+940x530',
+            'timestamp': 1604417980,
             'ext': 'mp4',
-            'title': 'Mexico: Stealing Petrol to Survive',
-            'upload_date': '20190628',
         },
+        'params': {'skip_download': 'm3u8'}
     }, {
-        'url': 'https://www.arte.tv/pl/videos/100103-000-A/usa-dyskryminacja-na-porodowce/',
+        'url': 'https://api.arte.tv/api/player/v2/config/de/100605-013-A',
         'only_matching': True,
     }, {
-        'url': 'https://api.arte.tv/api/player/v2/config/de/100605-013-A',
+        'url': 'https://api.arte.tv/api/player/v2/config/de/LIVE',
         'only_matching': True,
     }]
 
+    _GEO_BYPASS = True
+
+    _LANG_MAP = {  # ISO639 -> French abbreviations
+        'fr': 'F',
+        'de': 'A',
+        'en': 'E[ANG]',
+        'es': 'E[ESP]',
+        'it': 'E[ITA]',
+        'pl': 'E[POL]',
+        # XXX: probably means mixed; <https://www.arte.tv/en/videos/107710-029-A/dispatches-from-ukraine-local-journalists-report/>
+        # uses this code for audio that happens to be in Ukrainian, but the manifest uses the ISO code 'mul' (mixed)
+        'mul': 'EU',
+    }
+
+    _VERSION_CODE_RE = re.compile(r'''(?x)
+        V
+        (?P<original_voice>O?)
+        (?P<vlang>[FA]|E\[[A-Z]+\]|EU)?
+        (?P<audio_desc>AUD|)
+        (?:
+            (?P<has_sub>-ST)
+            (?P<sdh_sub>M?)
+            (?P<sub_lang>[FA]|E\[[A-Z]+\]|EU)
+        )?
+    ''')
+
+    # all obtained by exhaustive testing
+    _COUNTRIES_MAP = {
+        'DE_FR': {
+            'BL', 'DE', 'FR', 'GF', 'GP', 'MF', 'MQ', 'NC',
+            'PF', 'PM', 'RE', 'WF', 'YT',
+        },
+        # with both of the below 'BE' sometimes works, sometimes doesn't
+        'EUR_DE_FR': {
+            'AT', 'BL', 'CH', 'DE', 'FR', 'GF', 'GP', 'LI',
+            'MC', 'MF', 'MQ', 'NC', 'PF', 'PM', 'RE', 'WF',
+            'YT',
+        },
+        'SAT': {
+            'AD', 'AT', 'AX', 'BG', 'BL', 'CH', 'CY', 'CZ',
+            'DE', 'DK', 'EE', 'ES', 'FI', 'FR', 'GB', 'GF',
+            'GR', 'HR', 'HU', 'IE', 'IS', 'IT', 'KN', 'LI',
+            'LT', 'LU', 'LV', 'MC', 'MF', 'MQ', 'MT', 'NC',
+            'NL', 'NO', 'PF', 'PL', 'PM', 'PT', 'RE', 'RO',
+            'SE', 'SI', 'SK', 'SM', 'VA', 'WF', 'YT',
+        },
+    }
+
     def _real_extract(self, url):
         mobj = self._match_valid_url(url)
         video_id = mobj.group('id')
         lang = mobj.group('lang') or mobj.group('lang_2')
+        langauge_code = self._LANG_MAP.get(lang)
 
-        info = self._download_json(
-            '%s/config/%s/%s' % (self._API_BASE, lang, video_id), video_id)
-        player_info = info['videoJsonPlayer']
-
-        vsr = try_get(player_info, lambda x: x['VSR'], dict)
-        if not vsr:
-            error = None
-            if try_get(player_info, lambda x: x['custom_msg']['type']) == 'error':
-                error = try_get(
-                    player_info, lambda x: x['custom_msg']['msg'], compat_str)
-            if not error:
-                error = 'Video %s is not available' % player_info.get('VID') or video_id
-            raise ExtractorError(error, expected=True)
-
-        upload_date_str = player_info.get('shootingDate')
-        if not upload_date_str:
-            upload_date_str = (player_info.get('VRA') or player_info.get('VDA') or '').split(' ')[0]
-
-        title = (player_info.get('VTI') or player_info['VID']).strip()
-        subtitle = player_info.get('VSU', '').strip()
-        if subtitle:
-            title += ' - %s' % subtitle
-
-        qfunc = qualities(['MQ', 'HQ', 'EQ', 'SQ'])
-
-        LANGS = {
-            'fr': 'F',
-            'de': 'A',
-            'en': 'E[ANG]',
-            'es': 'E[ESP]',
-            'it': 'E[ITA]',
-            'pl': 'E[POL]',
-        }
-
-        langcode = LANGS.get(lang, lang)
-
-        formats = []
-        for format_id, format_dict in vsr.items():
-            f = dict(format_dict)
-            format_url = url_or_none(f.get('url'))
-            streamer = f.get('streamer')
-            if not format_url and not streamer:
-                continue
-            versionCode = f.get('versionCode')
-            l = re.escape(langcode)
+        config = self._download_json(f'{self._API_BASE}/config/{lang}/{video_id}', video_id)
 
-            # Language preference from most to least priority
-            # Reference: section 6.8 of
-            # https://www.arte.tv/sites/en/corporate/files/complete-technical-guidelines-arte-geie-v1-07-1.pdf
-            PREFERENCES = (
-                # original version in requested language, without subtitles
-                r'VO{0}$'.format(l),
-                # original version in requested language, with partial subtitles in requested language
-                r'VO{0}-ST{0}$'.format(l),
-                # original version in requested language, with subtitles for the deaf and hard-of-hearing in requested language
-                r'VO{0}-STM{0}$'.format(l),
-                # non-original (dubbed) version in requested language, without subtitles
-                r'V{0}$'.format(l),
-                # non-original (dubbed) version in requested language, with subtitles partial subtitles in requested language
-                r'V{0}-ST{0}$'.format(l),
-                # non-original (dubbed) version in requested language, with subtitles for the deaf and hard-of-hearing in requested language
-                r'V{0}-STM{0}$'.format(l),
-                # original version in requested language, with partial subtitles in different language
-                r'VO{0}-ST(?!{0}).+?$'.format(l),
-                # original version in requested language, with subtitles for the deaf and hard-of-hearing in different language
-                r'VO{0}-STM(?!{0}).+?$'.format(l),
-                # original version in different language, with partial subtitles in requested language
-                r'VO(?:(?!{0}).+?)?-ST{0}$'.format(l),
-                # original version in different language, with subtitles for the deaf and hard-of-hearing in requested language
-                r'VO(?:(?!{0}).+?)?-STM{0}$'.format(l),
-                # original version in different language, without subtitles
-                r'VO(?:(?!{0}))?$'.format(l),
-                # original version in different language, with partial subtitles in different language
-                r'VO(?:(?!{0}).+?)?-ST(?!{0}).+?$'.format(l),
-                # original version in different language, with subtitles for the deaf and hard-of-hearing in different language
-                r'VO(?:(?!{0}).+?)?-STM(?!{0}).+?$'.format(l),
-            )
-
-            for pref, p in enumerate(PREFERENCES):
-                if re.match(p, versionCode):
-                    lang_pref = len(PREFERENCES) - pref
-                    break
-            else:
-                lang_pref = -1
-            format_note = '%s, %s' % (f.get('versionCode'), f.get('versionLibelle'))
-
-            media_type = f.get('mediaType')
-            if media_type == 'hls':
-                m3u8_formats = self._extract_m3u8_formats(
-                    format_url, video_id, 'mp4', entry_protocol='m3u8_native',
-                    m3u8_id=format_id, fatal=False)
-                for m3u8_format in m3u8_formats:
-                    m3u8_format.update({
+        geoblocking = traverse_obj(config, ('data', 'attributes', 'restriction', 'geoblocking')) or {}
+        if geoblocking.get('restrictedArea'):
+            raise GeoRestrictedError(f'Video restricted to {geoblocking["code"]!r}',
+                                     countries=self._COUNTRIES_MAP.get(geoblocking['code'], ('DE', 'FR')))
+
+        if not traverse_obj(config, ('data', 'attributes', 'rights')):
+            # Eg: https://www.arte.tv/de/videos/097407-215-A/28-minuten
+            # Eg: https://www.arte.tv/es/videos/104351-002-A/serviteur-du-peuple-1-23
+            raise ExtractorError(
+                'Video is not available in this language edition of Arte or broadcast rights expired', expected=True)
+
+        formats, subtitles = [], {}
+        for stream in config['data']['attributes']['streams']:
+            # official player contains code like `e.get("versions")[0].eStat.ml5`
+            stream_version = stream['versions'][0]
+            stream_version_code = stream_version['eStat']['ml5']
+
+            lang_pref = -1
+            m = self._VERSION_CODE_RE.match(stream_version_code)
+            if m:
+                lang_pref = int(''.join('01'[x] for x in (
+                    m.group('vlang') == langauge_code,      # we prefer voice in the requested language
+                    not m.group('audio_desc'),              # and not the audio description version
+                    bool(m.group('original_voice')),        # but if voice is not in the requested language, at least choose the original voice
+                    m.group('sub_lang') == langauge_code,   # if subtitles are present, we prefer them in the requested language
+                    not m.group('has_sub'),                 # but we prefer no subtitles otherwise
+                    not m.group('sdh_sub'),                 # and we prefer not the hard-of-hearing subtitles if there are subtitles
+                )))
+
+            if stream['protocol'].startswith('HLS'):
+                fmts, subs = self._extract_m3u8_formats_and_subtitles(
+                    stream['url'], video_id=video_id, ext='mp4', m3u8_id=stream_version_code, fatal=False)
+                for fmt in fmts:
+                    fmt.update({
+                        'format_note': f'{stream_version.get("label", "unknown")} [{stream_version.get("shortLabel", "?")}]',
                         'language_preference': lang_pref,
-                        'format_note': format_note,
                     })
-                formats.extend(m3u8_formats)
-                continue
+                formats.extend(fmts)
+                self._merge_subtitles(subs, target=subtitles)
+
+            elif stream['protocol'] in ('HTTPS', 'RTMP'):
+                formats.append({
+                    'format_id': f'{stream["protocol"]}-{stream_version_code}',
+                    'url': stream['url'],
+                    'format_note': f'{stream_version.get("label", "unknown")} [{stream_version.get("shortLabel", "?")}]',
+                    'language_preference': lang_pref,
+                    # 'ext': 'mp4',  # XXX: may or may not be necessary, at least for HTTPS
+                })
 
-            format = {
-                'format_id': format_id,
-                'language_preference': lang_pref,
-                'format_note': format_note,
-                'width': int_or_none(f.get('width')),
-                'height': int_or_none(f.get('height')),
-                'tbr': int_or_none(f.get('bitrate')),
-                'quality': qfunc(f.get('quality')),
-            }
-
-            if media_type == 'rtmp':
-                format['url'] = f['streamer']
-                format['play_path'] = 'mp4:' + f['url']
-                format['ext'] = 'flv'
             else:
-                format['url'] = f['url']
+                self.report_warning(f'Skipping stream with unknown protocol {stream["protocol"]}')
 
-            formats.append(format)
+            # TODO: chapters from stream['segments']?
+            # The JS also looks for chapters in config['data']['attributes']['chapters'],
+            # but I am yet to find a video having those
 
-        # For this extractor, quality only represents the relative quality
-        # with respect to other formats with the same resolution
-        self._sort_formats(formats, ('res', 'quality'))
+        self._sort_formats(formats)
+
+        metadata = config['data']['attributes']['metadata']
 
         return {
-            'id': player_info.get('VID') or video_id,
-            'title': title,
-            'description': player_info.get('VDE') or player_info.get('V7T'),
-            'upload_date': unified_strdate(upload_date_str),
-            'thumbnail': player_info.get('programImage') or player_info.get('VTU', {}).get('IUR'),
+            'id': metadata['providerId'],
+            'webpage_url': traverse_obj(metadata, ('link', 'url')),
+            'title': metadata.get('subtitle'),
+            'alt_title': metadata.get('title'),
+            'description': metadata.get('description'),
+            'duration': traverse_obj(metadata, ('duration', 'seconds')),
+            'language': metadata.get('language'),
+            'timestamp': traverse_obj(config, ('data', 'attributes', 'rights', 'begin'), expected_type=parse_iso8601),
+            'is_live': config['data']['attributes'].get('live', False),
             'formats': formats,
+            'subtitles': subtitles,
+            'thumbnails': [
+                {'url': image['url'], 'id': image.get('caption')}
+                for image in metadata.get('images') or [] if url_or_none(image.get('url'))
+            ],
         }
 
 
@@ -194,6 +199,7 @@ class ArteTVEmbedIE(InfoExtractor):
             'description': 'md5:be40b667f45189632b78c1425c7c2ce1',
             'upload_date': '20201116',
         },
+        'skip': 'No video available'
     }, {
         'url': 'https://www.arte.tv/player/v3/index.php?json_url=https://api.arte.tv/api/player/v2/config/de/100605-013-A',
         'only_matching': True,
@@ -217,44 +223,36 @@ class ArteTVPlaylistIE(ArteTVBaseIE):
     _VALID_URL = r'https?://(?:www\.)?arte\.tv/(?P<lang>%s)/videos/(?P<id>RC-\d{6})' % ArteTVBaseIE._ARTE_LANGUAGES
     _TESTS = [{
         'url': 'https://www.arte.tv/en/videos/RC-016954/earn-a-living/',
-        'info_dict': {
-            'id': 'RC-016954',
-            'title': 'Earn a Living',
-            'description': 'md5:d322c55011514b3a7241f7fb80d494c2',
-        },
-        'playlist_mincount': 6,
+        'only_matching': True,
     }, {
         'url': 'https://www.arte.tv/pl/videos/RC-014123/arte-reportage/',
-        'only_matching': True,
+        'playlist_mincount': 100,
+        'info_dict': {
+            'description': 'md5:84e7bf1feda248bc325ebfac818c476e',
+            'id': 'RC-014123',
+            'title': 'ARTE Reportage - najlepsze reportaże',
+        },
     }]
 
     def _real_extract(self, url):
-        lang, playlist_id = self._match_valid_url(url).groups()
-        collection = self._download_json(
-            '%s/collectionData/%s/%s?source=videos'
-            % (self._API_BASE, lang, playlist_id), playlist_id)
-        entries = []
-        for video in collection['videos']:
-            if not isinstance(video, dict):
-                continue
-            video_url = url_or_none(video.get('url')) or url_or_none(video.get('jsonUrl'))
-            if not video_url:
-                continue
-            video_id = video.get('programId')
-            entries.append({
-                '_type': 'url_transparent',
-                'url': video_url,
-                'id': video_id,
-                'title': video.get('title'),
-                'alt_title': video.get('subtitle'),
-                'thumbnail': url_or_none(try_get(video, lambda x: x['mainImage']['url'], compat_str)),
-                'duration': int_or_none(video.get('durationSeconds')),
-                'view_count': int_or_none(video.get('views')),
-                'ie_key': ArteTVIE.ie_key(),
-            })
-        title = collection.get('title')
-        description = collection.get('shortDescription') or collection.get('teaserText')
-        return self.playlist_result(entries, playlist_id, title, description)
+        lang, playlist_id = self._match_valid_url(url).group('lang', 'id')
+        playlist = self._download_json(
+            f'{self._API_BASE}/playlist/{lang}/{playlist_id}', playlist_id)['data']['attributes']
+
+        entries = [{
+            '_type': 'url_transparent',
+            'url': video['config']['url'],
+            'ie_key': ArteTVIE.ie_key(),
+            'id': video.get('providerId'),
+            'title': video.get('title'),
+            'alt_title': video.get('subtitle'),
+            'thumbnail': url_or_none(traverse_obj(video, ('mainImage', 'url'))),
+            'duration': int_or_none(traverse_obj(video, ('duration', 'seconds'))),
+        } for video in traverse_obj(playlist, ('items', lambda _, v: v['config']['url']))]
+
+        return self.playlist_result(entries, playlist_id,
+                                    traverse_obj(playlist, ('metadata', 'title')),
+                                    traverse_obj(playlist, ('metadata', 'description')))
 
 
 class ArteTVCategoryIE(ArteTVBaseIE):
@@ -267,14 +265,13 @@ class ArteTVCategoryIE(ArteTVBaseIE):
             'description': 'Investigative documentary series, geopolitical analysis, and international commentary',
         },
         'playlist_mincount': 13,
-    },
-    ]
+    }]
 
     @classmethod
     def suitable(cls, url):
         return (
             not any(ie.suitable(url) for ie in (ArteTVIE, ArteTVPlaylistIE, ))
-            and super(ArteTVCategoryIE, cls).suitable(url))
+            and super().suitable(url))
 
     def _real_extract(self, url):
         lang, playlist_id = self._match_valid_url(url).groups()
