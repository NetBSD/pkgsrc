$NetBSD: patch-src_mess_tools_floptool_floptool.mak,v 1.1 2015/01/29 20:00:29 wiz Exp $

--- src/mess/tools/floptool/floptool.mak.orig	2015-01-28 09:20:10.000000000 +0000
+++ src/mess/tools/floptool/floptool.mak
@@ -36,4 +36,4 @@ FLOPTOOL_OBJS = \
 # TODO: Visual Studio wants $(FLAC_LIB) and $(7Z_LIB) during linking...
 $(FLOPTOOL): $(FLOPTOOL_OBJS) $(FORMATS_LIB) $(LIBEMU) $(LIBUTIL) $(EXPAT) $(ZLIB) $(LIBOCORE) $(FLAC_LIB) $(7Z_LIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
