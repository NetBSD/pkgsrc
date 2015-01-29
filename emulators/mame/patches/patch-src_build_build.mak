$NetBSD: patch-src_build_build.mak,v 1.2 2015/01/29 20:08:16 wiz Exp $

Fix linking against pkgsrc libraries.
https://github.com/mamedev/mame/pull/123

--- src/build/build.mak.orig	2015-01-28 09:20:10.000000000 +0000
+++ src/build/build.mak
@@ -60,7 +60,7 @@ MAKEDEPOBJS = \
 
 $(MAKEDEP_TARGET): $(MAKEDEPOBJS) $(LIBOCORE) $(ZLIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -79,7 +79,7 @@ MAKEMAKOBJS = \
 
 $(MAKEMAK_TARGET): $(MAKEMAKOBJS) $(LIBOCORE) $(ZLIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
@@ -98,7 +98,7 @@ MAKELISTOBJS = \
 
 $(MAKELIST_TARGET): $(MAKELISTOBJS) $(LIBOCORE) $(ZLIB)
 	@echo Linking $@...
-	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@
+	$(LD) $(LDFLAGS) $^ $(BASELIBS) -o $@ $(LIBS)
 
 
 
