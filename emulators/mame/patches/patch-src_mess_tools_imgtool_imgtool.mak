$NetBSD: patch-src_mess_tools_imgtool_imgtool.mak,v 1.1 2015/01/29 20:00:29 wiz Exp $

--- src/mess/tools/imgtool/imgtool.mak.orig	2015-01-28 09:20:10.000000000 +0000
+++ src/mess/tools/imgtool/imgtool.mak
@@ -76,4 +76,4 @@ IMGTOOL_OBJS = \
 
 $(IMGTOOL): $(IMGTOOL_OBJS) $(LIBIMGTOOL) $(FORMATS_LIB) $(LIBEMU) $(LIBUTIL) $(EXPAT) $(ZLIB) $(FLAC_LIB) $(7Z_LIB) $(LIBOCORE)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
