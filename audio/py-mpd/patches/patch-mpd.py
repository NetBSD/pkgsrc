$NetBSD: patch-mpd.py,v 1.1 2014/01/17 14:47:25 wiz Exp $

python-3.x compatibility.

--- mpd.py.orig	2010-12-14 00:46:05.000000000 +0000
+++ mpd.py
@@ -396,7 +396,7 @@ class MPDClient(object):
                 sock = socket.socket(af, socktype, proto)
                 sock.connect(sa)
                 return sock
-            except socket.error, err:
+            except socket.error as err:
                 if sock is not None:
                     sock.close()
         if err is not None:
