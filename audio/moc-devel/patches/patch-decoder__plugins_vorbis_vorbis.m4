$NetBSD: patch-decoder__plugins_vorbis_vorbis.m4,v 1.1 2013/02/10 08:39:00 ryoon Exp $

--- decoder_plugins/vorbis/vorbis.m4.orig	2012-04-16 03:18:59.000000000 +0000
+++ decoder_plugins/vorbis/vorbis.m4
@@ -3,7 +3,7 @@ dnl vorbis
 AC_ARG_WITH(vorbis, AS_HELP_STRING([--without-vorbis],
                                    [Compile without Ogg Vorbis support]))
 
-if test "x$with_vorbis" == "xtremor"
+if test "x$with_vorbis" = "xtremor"
 then
 	PKG_CHECK_MODULES(OGG_VORBIS,
 			  [vorbisidec >= 1.0],
