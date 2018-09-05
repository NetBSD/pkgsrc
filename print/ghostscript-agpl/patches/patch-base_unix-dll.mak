$NetBSD: patch-base_unix-dll.mak,v 1.4 2018/09/05 13:19:40 adam Exp $

Use correct shared library naming on Darwin.
Add some rpaths.

--- base/unix-dll.mak.orig	2018-09-03 08:50:27.000000000 +0000
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
 $(GSSOC_XE): gs-so-links-subtarget $(PSSRC)dxmainc.c $(UNIX_DLL_MAK) $(MAKEDIRS)
 	$(GLCC) $(GLO_)dxmainc.$(OBJ) $(C_) $(PSSRC)dxmainc.c
-	$(GLCC) -L$(BINDIR) $(LDFLAGS) $(O_) $(GSSOC_XE) $(GLOBJ)dxmainc.$(OBJ) -l$(GS_SO_BASE)
+	$(GLCC) -L$(BINDIR) -L$(PREFIX)/lib -Wl,-R$(PREFIX)/lib $(LDFLAGS) $(O_) $(GSSOC_XE) $(GLOBJ)dxmainc.$(OBJ) -l$(GS_SO_BASE)
 
 $(GSSOX_XE): gs-so-links-subtarget $(PSSRC)$(SOC_LOADER).c $(UNIX_DLL_MAK) $(MAKEDIRS)
 	$(GLCC) $(SOC_CFLAGS) $(GLO_)$(SOC_LOADER).$(OBJ) $(C_) $(PSSRC)$(SOC_LOADER).c
-	$(GLCC) -L$(BINDIR) $(LDFLAGS) $(O_) $(GSSOX_XE) $(GLOBJ)$(SOC_LOADER).$(OBJ) -l$(GS_SO_BASE) $(SOC_LIBS)
+	$(GLCC) -L$(BINDIR) -L$(PREFIX)/lib -Wl,-R$(PREFIX)/lib $(LDFLAGS) $(O_) $(GSSOX_XE) $(GLOBJ)$(SOC_LOADER).$(OBJ) -l$(GS_SO_BASE) $(SOC_LIBS)
 
 $(PCLSOC_XE): gpcl6-so-links-subtarget $(UNIX_DLL_MAK) $(PLOBJ)$(REALMAIN_SRC).$(OBJ) $(MAKEDIRS)
 	$(GLCC) -L$(BINDIR) $(LDFLAGS) $(O_) $(PCLSOC_XE) $(PLOBJ)$(REALMAIN_SRC).$(OBJ) -l$(PCL_SO_BASE)
