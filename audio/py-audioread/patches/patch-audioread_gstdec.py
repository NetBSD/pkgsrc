$NetBSD: patch-audioread_gstdec.py,v 1.1 2014/01/17 14:35:06 wiz Exp $

Use print() function for python-3.x compatibility.

--- audioread/gstdec.py.orig	2013-04-24 17:08:52.000000000 +0000
+++ audioread/gstdec.py
@@ -366,8 +366,8 @@ if __name__ == '__main__':
     for path in sys.argv[1:]:
         path = os.path.abspath(os.path.expanduser(path))
         with GstAudioFile(path) as f:
-            print f.channels
-            print f.samplerate
-            print f.duration
+            print(f.channels)
+            print(f.samplerate)
+            print(f.duration)
             for s in f:
-                print len(s), ord(s[0])
+                print(len(s), ord(s[0]))
