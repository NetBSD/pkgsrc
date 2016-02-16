$NetBSD: patch-decoder__plugins_vorbis_vorbis.m4,v 1.1 2016/02/16 08:46:01 leot Exp $

Avoid the use of "==" operator in test(1).

--- decoder_plugins/vorbis/vorbis.m4.orig	2012-07-05 06:51:44.000000000 +0000
+++ decoder_plugins/vorbis/vorbis.m4
@@ -3,7 +3,7 @@ dnl vorbis
 AC_ARG_WITH(vorbis, AS_HELP_STRING([--without-vorbis],
                                    [Compile without Ogg Vorbis support]))
 
-if test "x$with_vorbis" == "xtremor"
+if test "x$with_vorbis" = "xtremor"
 then
 	PKG_CHECK_MODULES(OGG_VORBIS,
 			  [vorbisidec >= 1.0],
