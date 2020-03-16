$NetBSD: patch-DOCS_man_ao.rst,v 1.1 2020/03/16 20:31:44 nia Exp $

NetBSD audio support.

--- DOCS/man/ao.rst.orig	2020-01-26 20:31:54.000000000 +0000
+++ DOCS/man/ao.rst
@@ -177,6 +177,9 @@ Available audio output drivers are:
         Sets the number of extra audio buffers in mpv. Usually needs not be
         changed.
 
+``netbsd``
+    Audio output to the NetBSD sound system
+
 ``null``
     Produces no audio output but maintains video playback speed. You can use
     ``--ao=null --ao-null-untimed`` for benchmarking.
