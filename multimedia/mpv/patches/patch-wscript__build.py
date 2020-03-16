$NetBSD: patch-wscript__build.py,v 1.1 2020/03/16 20:31:44 nia Exp $

NetBSD audio support.

--- wscript_build.py.orig	2020-01-26 20:31:54.000000000 +0000
+++ wscript_build.py
@@ -252,6 +252,7 @@ def build(ctx):
         ( "audio/out/ao_coreaudio_utils.c",      "coreaudio || audiounit" ),
         ( "audio/out/ao_jack.c",                 "jack" ),
         ( "audio/out/ao_lavc.c" ),
+        ( "audio/out/ao_netbsd.c",               "netbsd-audio" ),
         ( "audio/out/ao_null.c" ),
         ( "audio/out/ao_openal.c",               "openal" ),
         ( "audio/out/ao_opensles.c",             "opensles" ),
