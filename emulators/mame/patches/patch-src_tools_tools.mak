$NetBSD: patch-src_tools_tools.mak,v 1.1 2015/01/29 20:00:29 wiz Exp $

--- src/tools/tools.mak.orig	2015-01-28 09:20:10.000000000 +0000
+++ src/tools/tools.mak
@@ -74,7 +74,7 @@ ROMCMPOBJS = \
 
 romcmp$(EXE): $(ROMCMPOBJS) $(LIBUTIL) $(ZLIB) $(EXPAT) $(LIBOCORE)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -88,7 +88,7 @@ CHDMANOBJS = \
 chdman$(EXE): $(CHDMANOBJS) $(LIBUTIL) $(ZLIB) $(EXPAT) $(FLAC_LIB) $(7Z_LIB) $(LIBOCORE)
 	$(CC) $(CDEFS) $(CFLAGS) -c $(SRC)/version.c -o $(VERSIONOBJ)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $(VERSIONOBJ) $^ $(BASELIBS) $(FLAC_LIB) -o $@
+	$(LD) $(LDFLAGS) $(VERSIONOBJ) $^ $(BASELIBS) $(FLAC_LIB) -o $@ $(LIBS)
 
 
 
@@ -101,7 +101,7 @@ JEDUTILOBJS = \
 
 jedutil$(EXE): $(JEDUTILOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -115,7 +115,7 @@ UNIDASMOBJS = \
 # TODO: Visual Studio wants $(FLAC_LIB) and $(7Z_LIB) during linking...
 unidasm$(EXE): $(UNIDASMOBJS) $(LIBDASM) $(LIBEMU) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(EXPAT) $(FLAC_LIB) $(7Z_LIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -128,7 +128,7 @@ LDRESAMPLEOBJS = \
 
 ldresample$(EXE): $(LDRESAMPLEOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(FLAC_LIB) $(7Z_LIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) $(FLAC_LIB) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) $(FLAC_LIB) -o $@ $(LIBS)
 
 
 
@@ -141,7 +141,7 @@ LDVERIFYOBJS = \
 
 ldverify$(EXE): $(LDVERIFYOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(FLAC_LIB) $(7Z_LIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) $(FLAC_LIB) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) $(FLAC_LIB) -o $@ $(LIBS)
 
 
 
@@ -154,7 +154,7 @@ REGREPOBJS = \
 
 regrep$(EXE): $(REGREPOBJS) $(LIBUTIL) $(FLAC_LIB) $(LIBOCORE) $(ZLIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -167,7 +167,7 @@ SRCCLEANOBJS = \
 
 srcclean$(EXE): $(SRCCLEANOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -180,7 +180,7 @@ SRC2HTMLOBJS = \
 
 src2html$(EXE): $(SRC2HTMLOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -194,7 +194,7 @@ SPLITOBJS = \
 # TODO: Visual Studio wants $(FLAC_LIB) and $(7Z_LIB) during linking...
 split$(EXE): $(SPLITOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(EXPAT) $(FLAC_LIB) $(7Z_LIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -207,7 +207,7 @@ PNGCMPOBJS = \
 
 pngcmp$(EXE): $(PNGCMPOBJS) $(LIBUTIL) $(FLAC_LIB) $(LIBOCORE) $(ZLIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 #-------------------------------------------------
 # nltool
@@ -219,5 +219,5 @@ NLTOOLOBJS = \
 
 nltool$(EXE): $(NLTOOLOBJS) $(LIBUTIL) $(LIBOCORE) $(ZLIB) $(EXPAT)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
