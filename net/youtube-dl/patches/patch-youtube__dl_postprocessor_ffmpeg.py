$NetBSD: patch-youtube__dl_postprocessor_ffmpeg.py,v 1.4 2018/07/14 11:27:05 leot Exp $

Also look and use ffmpeg[234]/ffproble[234] if possible, preferring
the unversioned one (i.e. selected via alternatives framework)
or the newest one.

--- youtube_dl/postprocessor/ffmpeg.py.orig	2018-07-03 22:29:01.000000000 +0000
+++ youtube_dl/postprocessor/ffmpeg.py
@@ -76,7 +76,7 @@ class FFmpegPostProcessor(PostProcessor)
         return FFmpegPostProcessor(downloader)._versions
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2']
         prefer_ffmpeg = True
 
         self.basename = None
@@ -104,7 +104,7 @@ class FFmpegPostProcessor(PostProcessor)
                         self._versions = {}
                         return None
                     location = os.path.dirname(os.path.abspath(location))
-                    if basename in ('ffmpeg', 'ffprobe'):
+                    if basename in ('ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2'):
                         prefer_ffmpeg = True
 
                 self._paths = dict(
@@ -118,18 +118,18 @@ class FFmpegPostProcessor(PostProcessor)
             self._paths = dict((p, p) for p in programs)
 
         if prefer_ffmpeg is False:
-            prefs = ('avconv', 'ffmpeg')
+            prefs = ('avconv', 'ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2')
         else:
-            prefs = ('ffmpeg', 'avconv')
+            prefs = ('ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'avconv')
         for p in prefs:
             if self._versions[p]:
                 self.basename = p
                 break
 
         if prefer_ffmpeg is False:
-            prefs = ('avprobe', 'ffprobe')
+            prefs = ('avprobe', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2')
         else:
-            prefs = ('ffprobe', 'avprobe')
+            prefs = ('ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2', 'avprobe')
         for p in prefs:
             if self._versions[p]:
                 self.probe_basename = p
