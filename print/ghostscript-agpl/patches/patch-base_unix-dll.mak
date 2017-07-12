$NetBSD: patch-base_unix-dll.mak,v 1.3 2017/07/12 08:55:36 wiz Exp $

Use correct shared library naming on Darwin.
Add some rpaths.

--- base/unix-dll.mak.orig	2017-03-16 10:12:02.000000000 +0000
+++ base/unix-dll.mak
@@ -91,10 +91,10 @@ GPDL_SONAME_MAJOR_MINOR=$(GPDL_SONAME_BA
 
 
 # MacOS X
-#GS_SOEXT=dylib
-#GS_SONAME=$(GS_SONAME_BASE).$(GS_SOEXT)
-#GS_SONAME_MAJOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_SOEXT)
-#GS_SONAME_MAJOR_MINOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR).$(GS_SOEXT)
+#Darwin#GS_SOEXT=dylib
+#Darwin#GS_SONAME=$(GS_SONAME_BASE).$(GS_SOEXT)
+#Darwin#GS_SONAME_MAJOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_SOEXT)
+#Darwin#GS_SONAME_MAJOR_MINOR=$(GS_SONAME_BASE).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR).$(GS_SOEXT)
 #LDFLAGS_SO=-dynamiclib -flat_namespace
 #LDFLAGS_SO_MAC=-dynamiclib -install_name $(GS_SONAME_MAJOR_MINOR)
 #LDFLAGS_SO=-dynamiclib -install_name $(FRAMEWORK_NAME)
@@ -171,11 +171,11 @@ gpdl-so-links-subtarget: $(GPDL_SO) $(UN
 # Build the small Ghostscript loaders, with Gtk+ and without
 $(GSSOC_XE): gs-so-links-subtarget $(PSSRC)$(SOC_LOADER) $(UNIX_DLL_MAK) $(MAKEDIRS)
 	$(GLCC) -g -o $(GSSOC_XE) $(PSSRC)dxmainc.c \
-	-L$(BINDIR) -l$(GS_SO_BASE)
+	-L$(BINDIR) -L$(PREFIX)/lib -Wl,-R$(PREFIX)/lib -l$(GS_SO_BASE) $(LDFLAGS)
 
 $(GSSOX_XE): gs-so-links-subtarget $(PSSRC)$(SOC_LOADER) $(UNIX_DLL_MAK) $(MAKEDIRS)
 	$(GLCC) -g $(SOC_CFLAGS) -o $(GSSOX_XE) $(PSSRC)$(SOC_LOADER) \
-	-L$(BINDIR) -l$(GS_SO_BASE) $(SOC_LIBS)
+	-L$(BINDIR) -L$(PREFIX)/lib -Wl,-R$(PREFIX)/lib -l$(GS_SO_BASE) $(SOC_LIBS) $(LDFLAGS)
 
 $(PCLSOC_XE): gpcl6-so-links-subtarget $(PLSRC)$(REALMAIN_SRC).c $(UNIX_DLL_MAK) $(MAKEDIRS)
 	$(GLCC) -g -o $(PCLSOC_XE) $(PLSRC)$(REALMAIN_SRC).c -L$(BINDIR) -l$(PCL_SO_BASE)
