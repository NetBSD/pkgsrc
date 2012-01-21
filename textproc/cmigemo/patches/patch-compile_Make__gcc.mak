$NetBSD: patch-compile_Make__gcc.mak,v 1.1.1.1 2012/01/21 13:38:41 obache Exp $

* libtoolize

--- compile/Make_gcc.mak.orig	2011-02-27 10:45:40.000000000 +0000
+++ compile/Make_gcc.mak
@@ -9,12 +9,12 @@
 ##############################################################################
 # ä¬ã´Ç…âûÇ∂ÇƒÇ±ÇÃïœêîÇïœçXÇ∑ÇÈ
 #
-libmigemo_LIB	= libmigemo.so.1.1.0
-libmigemo_DSO	= libmigemo.so.1
-libmigemo	= libmigemo.so
+libmigemo_LIB	= libmigemo.la
+libmigemo_DSO	= libmigemo.la
+libmigemo	= libmigemo.la
 EXEEXT		=
-CFLAGS_MIGEMO	= -fPIC
-LDFLAGS_MIGEMO	= -Wl,-rpath,.,-rpath,/usr/local/lib,-rpath,/usr/lib
+CFLAGS_MIGEMO	= -shared
+LDFLAGS_MIGEMO	= -rpath ${libdir}
 
 include config.mk
 include compile/unix.mak
@@ -27,16 +27,10 @@ include compile/clean.mak
 #
 $(libmigemo_LIB): $(libmigemo_DSO)
 $(libmigemo_DSO): $(libmigemo_OBJ)
-	$(CC) -shared -o $(libmigemo_LIB) -Wl,-soname,$@ $(libmigemo_OBJ)
-	$(RM) $@ $(libmigemo)
-	ln -s $(libmigemo_LIB) $@
-	ln -s $(libmigemo_LIB) $(libmigemo)
+	libtool --mode=link $(CC) $(CFLAGS_MIGEMO) $(LDFLAGS_MIGEMO) -o $(libmigemo_LIB) -version-number 1:1:0 $(libmigemo_OBJ)
 
 install-lib: $(libmigemo_DSO)
-	$(INSTALL_PROGRAM) $(libmigemo_LIB) $(libdir)
-	$(RM) $(libdir)/$(libmigemo_DSO) $(libdir)/$(libmigemo)
-	ln -s $(libmigemo_LIB) $(libdir)/$(libmigemo_DSO)
-	ln -s $(libmigemo_LIB) $(libdir)/$(libmigemo)
+	libtool --mode=install $(INSTALL_PROGRAM) $(libmigemo_LIB) $(libdir)
 
 uninstall-lib:
 	$(RM) $(libdir)/$(libmigemo_DSO)
