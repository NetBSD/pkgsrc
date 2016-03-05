$NetBSD: patch-youtube__dl_postprocessor_ffmpeg.py,v 1.1 2016/03/05 20:41:10 leot Exp $

Also look and use ffmpeg[23] if possible.

--- youtube_dl/postprocessor/ffmpeg.py.orig	2016-02-09 11:57:41.000000000 +0000
+++ youtube_dl/postprocessor/ffmpeg.py
@@ -51,7 +51,7 @@ class FFmpegPostProcessor(PostProcessor)
         return FFmpegPostProcessor(downloader)._versions
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffmpeg2', 'ffmpeg3', 'ffprobe', 'ffprobe2', 'ffprobe3']
         prefer_ffmpeg = False
 
         self.basename = None
@@ -79,7 +79,7 @@ class FFmpegPostProcessor(PostProcessor)
                         self._versions = {}
                         return None
                     location = os.path.dirname(os.path.abspath(location))
-                    if basename in ('ffmpeg', 'ffprobe'):
+                    if basename in ('ffmpeg', 'ffmpeg2', 'ffmpeg3', 'ffprobe', 'ffprobe2', 'ffprobe3'):
                         prefer_ffmpeg = True
 
                 self._paths = dict(
@@ -93,18 +93,18 @@ class FFmpegPostProcessor(PostProcessor)
             self._paths = dict((p, p) for p in programs)
 
         if prefer_ffmpeg:
-            prefs = ('ffmpeg', 'avconv')
+            prefs = ('ffmpeg', 'ffmpeg2', 'ffmpeg3', 'avconv')
         else:
-            prefs = ('avconv', 'ffmpeg')
+            prefs = ('avconv', 'ffmpeg', 'ffmpeg2', 'ffmpeg3')
         for p in prefs:
             if self._versions[p]:
                 self.basename = p
                 break
 
         if prefer_ffmpeg:
-            prefs = ('ffprobe', 'avprobe')
+            prefs = ('ffprobe', 'ffprobe2', 'ffprobe3', 'avprobe')
         else:
-            prefs = ('avprobe', 'ffprobe')
+            prefs = ('avprobe', 'ffprobe', 'ffprobe2', 'ffprobe3')
         for p in prefs:
             if self._versions[p]:
                 self.probe_basename = p
