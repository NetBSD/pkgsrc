$NetBSD: patch-base_unix-dll.mak,v 1.5 2022/01/22 13:51:55 triaxx Exp $

* Use correct shared library naming on Darwin.
* Add some rpaths.
* A build issue has been discussed on pkgsrc-users@ (https://mail-index.netbsd.org/pkgsrc-users/2019/06/13/msg028790.html)
  A fix has been provided upstream (https://bugs.ghostscript.com/show_bug.cgi?id=704844)

--- base/unix-dll.mak.orig	2021-09-27 07:44:02.000000000 +0000
+++ base/unix-dll.mak
@@ -100,10 +100,10 @@ GS_DLLEXT=$(DLL_EXT)
 
 
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
@@ -193,13 +193,16 @@ gpdl-so-links-subtarget: $(GPDL_SO) $(UN
 	$(NO_OP)
 
 # Build the small Ghostscript loaders, with Gtk+ and without
-$(GSSOC_XE): gs-so-links-subtarget $(PSSRC)dxmainc.c $(UNIX_DLL_MAK) $(MAKEDIRS)
+$(GLOBJ)dxmainc.$(OBJ): $(PSSRC)dxmainc.c $(UNIX_DLL_MAK) $(MAKEDIRS)
 	$(GLCC) $(GLO_)dxmainc.$(OBJ) $(C_) $(PSSRC)dxmainc.c
-	$(GLCC) -L$(BINDIR) $(LDFLAGS) $(O_) $(GSSOC_XE) $(GLOBJ)dxmainc.$(OBJ) -l$(GS_SO_BASE)
 
-$(GSSOX_XE): gs-so-links-subtarget $(PSSRC)$(SOC_LOADER).c $(UNIX_DLL_MAK) $(MAKEDIRS)
-	$(GLCC) $(SOC_CFLAGS) $(GLO_)$(SOC_LOADER).$(OBJ) $(C_) $(PSSRC)$(SOC_LOADER).c
-	$(GLCC) -L$(BINDIR) $(LDFLAGS) $(O_) $(GSSOX_XE) $(GLOBJ)$(SOC_LOADER).$(OBJ) -l$(GS_SO_BASE) $(SOC_LIBS)
+$(GSSOC_XE): gs-so-links-subtarget $(GLOBJ)dxmainc.$(OBJ) $(UNIX_DLL_MAK) $(MAKEDIRS)
+	$(GLCC) -L$(BINDIR) -L$(PREFIX)/lib -Wl,-R$(PREFIX)/lib $(LDFLAGS) $(O_) $(GSSOC_XE) $(GLOBJ)dxmainc.$(OBJ) -l$(GS_SO_BASE)
+
+$(GLO_)$(SOC_LOADER).$(OBJ): $(PSSRC)$(SOC_LOADER).c $(UNIX_DLL_MAK) $(MAKEDIRS)
+
+$(GSSOX_XE): gs-so-links-subtarget $(GLO_)$(SOC_LOADER).$(OBJ) $(UNIX_DLL_MAK) $(MAKEDIRS)
+	$(GLCC) -L$(BINDIR) -L$(PREFIX)/lib -Wl,-R$(PREFIX)/lib $(LDFLAGS) $(O_) $(GSSOX_XE) $(GLOBJ)$(SOC_LOADER).$(OBJ) -l$(GS_SO_BASE) $(SOC_LIBS)
 
 $(PCLSOC_XE): gpcl6-so-links-subtarget $(UNIX_DLL_MAK) $(PLOBJ)$(REALMAIN_SRC).$(OBJ) $(MAKEDIRS)
 	$(GLCC) -L$(BINDIR) $(LDFLAGS) $(O_) $(PCLSOC_XE) $(PLOBJ)$(REALMAIN_SRC).$(OBJ) -l$(PCL_SO_BASE)
