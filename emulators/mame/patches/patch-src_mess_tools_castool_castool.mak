$NetBSD: patch-src_mess_tools_castool_castool.mak,v 1.1 2015/01/29 20:00:29 wiz Exp $

--- src/mess/tools/castool/castool.mak.orig	2015-01-28 09:20:10.000000000 +0000
+++ src/mess/tools/castool/castool.mak
@@ -36,4 +36,4 @@ CASTOOL_OBJS = \
 # TODO: Visual Studio wants $(FLAC_LIB) and $(7Z_LIB) during linking...
 $(CASTOOL): $(CASTOOL_OBJS) $(FORMATS_LIB) $(LIBUTIL) $(EXPAT) $(ZLIB) $(LIBOCORE) $(FLAC_LIB) $(7Z_LIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
