$NetBSD: patch-yt__dlp_postprocessor_ffmpeg.py,v 1.5 2022/05/08 03:51:20 wiz Exp $

Also look and use ffmpeg[234]/ffprobe[234] if possible, preferring
the unversioned one (i.e. selected via alternatives framework)
or the newest one.
From: pkgsrc/net/youtube-dl

--- yt_dlp/postprocessor/ffmpeg.py.orig	2022-04-08 09:56:58.000000000 +0000
+++ yt_dlp/postprocessor/ffmpeg.py
@@ -91,7 +91,7 @@ class FFmpegPostProcessor(PostProcessor)
     _version_cache, _features_cache = {}, {}
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffmpeg5', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe5', 'ffprobe4', 'ffprobe3', 'ffprobe2']
 
         def get_ffmpeg_version(path, prog):
             if path in self._version_cache:
@@ -144,7 +144,7 @@ class FFmpegPostProcessor(PostProcessor)
                 basename = os.path.splitext(os.path.basename(location))[0]
                 basename = next((p for p in programs if basename.startswith(p)), 'ffmpeg')
                 dirname = os.path.dirname(os.path.abspath(location))
-                if basename in ('ffmpeg', 'ffprobe'):
+                if basename in ('ffmpeg', 'ffmpeg5', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe5', 'ffprobe4', 'ffprobe3', 'ffprobe2'):
                     prefer_ffmpeg = True
 
             self._paths = dict(
@@ -237,7 +237,7 @@ class FFmpegPostProcessor(PostProcessor)
         return None
 
     def get_metadata_object(self, path, opts=[]):
-        if self.probe_basename != 'ffprobe':
+        if not self.probe_basename.startswith('ffprobe'):
             if self.probe_available:
                 self.report_warning('Only ffprobe is supported for metadata extraction')
             raise PostProcessingError('ffprobe not found. Please install or provide the path using --ffmpeg-location')
