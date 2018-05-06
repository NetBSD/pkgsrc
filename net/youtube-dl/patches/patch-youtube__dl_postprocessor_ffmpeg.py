$NetBSD: patch-youtube__dl_postprocessor_ffmpeg.py,v 1.3 2018/05/06 10:22:59 leot Exp $

Also look and use ffmpeg[234]/ffproble[234] if possible, preferring
the unversioned one (i.e. selected via alternatives framework)
or the newest one.

--- youtube_dl/postprocessor/ffmpeg.py.orig	2016-02-09 11:57:41.000000000 +0000
+++ youtube_dl/postprocessor/ffmpeg.py
@@ -51,7 +51,7 @@ class FFmpegPostProcessor(PostProcessor)
         return FFmpegPostProcessor(downloader)._versions
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2']
         prefer_ffmpeg = False
 
         self.basename = None
@@ -79,7 +79,7 @@ class FFmpegPostProcessor(PostProcessor)
                         self._versions = {}
                         return None
                     location = os.path.dirname(os.path.abspath(location))
-                    if basename in ('ffmpeg', 'ffprobe'):
+                    if basename in ('ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2'):
                         prefer_ffmpeg = True
 
                 self._paths = dict(
@@ -93,18 +93,18 @@ class FFmpegPostProcessor(PostProcessor)
             self._paths = dict((p, p) for p in programs)
 
         if prefer_ffmpeg:
-            prefs = ('ffmpeg', 'avconv')
+            prefs = ('ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'avconv')
         else:
-            prefs = ('avconv', 'ffmpeg')
+            prefs = ('avconv', 'ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2')
         for p in prefs:
             if self._versions[p]:
                 self.basename = p
                 break
 
         if prefer_ffmpeg:
-            prefs = ('ffprobe', 'avprobe')
+            prefs = ('ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2', 'avprobe')
         else:
-            prefs = ('avprobe', 'ffprobe')
+            prefs = ('avprobe', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2')
         for p in prefs:
             if self._versions[p]:
                 self.probe_basename = p
