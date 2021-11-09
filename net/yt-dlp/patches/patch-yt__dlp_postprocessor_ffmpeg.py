$NetBSD: patch-yt__dlp_postprocessor_ffmpeg.py,v 1.1 2021/11/09 09:53:43 ryoon Exp $

Also look and use ffmpeg[234]/ffprobe[234] if possible, preferring
the unversioned one (i.e. selected via alternatives framework)
or the newest one.
From: pkgsrc/net/youtube-dl

--- yt_dlp/postprocessor/ffmpeg.py.orig	2021-10-22 20:47:09.000000000 +0000
+++ yt_dlp/postprocessor/ffmpeg.py
@@ -78,7 +78,7 @@ class FFmpegPostProcessor(PostProcessor)
         return FFmpegPostProcessor(downloader)._versions
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2']
         prefer_ffmpeg = True
 
         def get_ffmpeg_version(path):
@@ -116,7 +116,7 @@ class FFmpegPostProcessor(PostProcessor)
                     basename = os.path.splitext(os.path.basename(location))[0]
                     basename = next((p for p in programs if basename.startswith(p)), 'ffmpeg')
                     dirname = os.path.dirname(os.path.abspath(location))
-                    if basename in ('ffmpeg', 'ffprobe'):
+                    if basename in ('ffmpeg', 'ffmpeg4', 'ffmpeg3', 'ffmpeg2', 'ffprobe', 'ffprobe4', 'ffprobe3', 'ffprobe2'):
                         prefer_ffmpeg = True
 
                 self._paths = dict(
@@ -131,18 +131,18 @@ class FFmpegPostProcessor(PostProcessor)
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
