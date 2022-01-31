$NetBSD: patch-yt__dlp_postprocessor_ffmpeg.py,v 1.4 2022/01/31 23:27:20 ryoon Exp $

Also look and use ffmpeg[234]/ffprobe[234] if possible, preferring
the unversioned one (i.e. selected via alternatives framework)
or the newest one.
From: pkgsrc/net/youtube-dl

--- yt_dlp/postprocessor/ffmpeg.py.orig	2021-12-27 02:29:52.000000000 +0000
+++ yt_dlp/postprocessor/ffmpeg.py
@@ -87,7 +87,7 @@ class FFmpegPostProcessor(PostProcessor)
         return FFmpegPostProcessor.get_version_and_features(downloader)[0]
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffmpeg5', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe5', 'ffprobe4', 'ffprobe3', 'ffprobe2']
 
         def get_ffmpeg_version(path, prog):
             out = _get_exe_version_output(path, ['-bsfs'])
@@ -137,7 +137,7 @@ class FFmpegPostProcessor(PostProcessor)
                 basename = os.path.splitext(os.path.basename(location))[0]
                 basename = next((p for p in programs if basename.startswith(p)), 'ffmpeg')
                 dirname = os.path.dirname(os.path.abspath(location))
-                if basename in ('ffmpeg', 'ffprobe'):
+                if basename in ('ffmpeg', 'ffmpeg5', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe5', 'ffprobe4', 'ffprobe3', 'ffprobe2'):
                     prefer_ffmpeg = True
 
             self._paths = dict(
@@ -150,18 +150,18 @@ class FFmpegPostProcessor(PostProcessor)
             get_ffmpeg_version(self._paths[p], p)
 
         if prefer_ffmpeg is False:
-            prefs = ('avconv', 'ffmpeg')
+            prefs = ('avconv', 'ffmpeg', 'ffmpeg5', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2')
         else:
-            prefs = ('ffmpeg', 'avconv')
+            prefs = ('ffmpeg', 'ffmpeg5', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'avconv')
         for p in prefs:
             if self._versions[p]:
                 self.basename = p
                 break
 
         if prefer_ffmpeg is False:
-            prefs = ('avprobe', 'ffprobe')
+            prefs = ('avprobe', 'ffprobe', 'ffprobe5', 'ffprobe4', 'ffprobe3', 'ffprobe2')
         else:
-            prefs = ('ffprobe', 'avprobe')
+            prefs = ('ffprobe', 'ffprobe5', 'ffprobe4', 'ffprobe3', 'ffprobe2', 'avprobe')
         for p in prefs:
             if self._versions[p]:
                 self.probe_basename = p
@@ -229,7 +229,7 @@ class FFmpegPostProcessor(PostProcessor)
         return None
 
     def get_metadata_object(self, path, opts=[]):
-        if self.probe_basename != 'ffprobe':
+        if not self.probe_basename.startswith('ffprobe'):
             if self.probe_available:
                 self.report_warning('Only ffprobe is supported for metadata extraction')
             raise PostProcessingError('ffprobe not found. Please install or provide the path using --ffmpeg-location')
