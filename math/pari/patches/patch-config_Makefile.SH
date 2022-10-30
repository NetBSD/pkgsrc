$NetBSD: patch-config_Makefile.SH,v 1.4 2022/10/30 10:00:15 nros Exp $

* libtoolize
* add rpath to X11 libs
* don't install docs implicitly

--- config/Makefile.SH.orig	2022-09-18 13:13:38.000000000 +0000
+++ config/Makefile.SH
@@ -57,8 +57,6 @@ case "$osname" in
   mingw)
     export_file='$(LIBPARI).def';
     export_exe='$(LIBPARI)_exe.def';;
-  darwin)
-    ld_install_name="-Wl,-install_name -Wl,\"$libdir\"/\$(LIBPARI_DYN)";;
 esac
 case "$osname" in
   mingw|cygwin)
@@ -88,7 +86,7 @@ win32)
   graph=plotWin32;;
 X11)
   PLOTCFLAGS="$PLOTCFLAGS $X11_INC"
-  PLOTLIBS="$PLOTLIBS $X11_LIBS"
+  PLOTLIBS="-Wl,-R${X11BASE}/lib $PLOTLIBS $X11_LIBS"
   plotrunpath=$X11
   graph=plotX;;
 *)
@@ -134,20 +132,11 @@ if test -n "$runpathprefix"; then
   RUNPTH=`$config_dir/ldflags "$LDneedsWl" $runpathprefix\\\$\(TOPDIR\)/$objdir$dir_sep"$tmp"`
 fi
 
-if test -z "$DLLD"; then
-  exec="gp-sta$exe_suff"; static=y
-else
-  exec="gp-sta$exe_suff gp-dyn$exe_suff"
-fi
 case "$sizeof_long" in
   4) numbits=32;;
   8) numbits=64;;
 esac
 dotest="env \"RUNTEST=\$(RUNTEST)\" \"GPTESTOPT=\$(GPTESTOPT)\" \"LD_LIBRARY_PATH=.$dir_sep\$\$LD_LIBRARY_PATH\" \$(SHELL) ../src/test/dotest $numbits \"$exe_suff\""
-case "$static" in
-  n) dft=dyn; libdft=lib-dyn; dfttarget="gp-dyn gp-sta";;
-  y) dft=sta; libdft= ; dfttarget="gp-sta";;
-esac
 
 CPPFLAGS="-I. -I$src/headers"
 if test "$has_dlopen" = builtin; then
@@ -176,16 +165,16 @@ RANLIB     = ranlib
 SIZEOF_LONG= $sizeof_long
 
 CC_FLAVOR  =
-CC         = $CC \$(CC_FLAVOR)
+CC         = \$(LIBTOOL) --mode=compile $CC \$(CC_FLAVOR)
 CPPFLAGS   = $CPPFLAGS
 CFLAGS     = $CFLAGS
 DLCFLAGS   = $DLCFLAGS
 KERNELCFLAGS  = $KERNELCFLAGS
 LD_FLAVOR  = \$(CC_FLAVOR)
-LD         = $LD \$(LD_FLAVOR)
+LD         = \$(LIBTOOL) --mode=link $LD \$(LD_FLAVOR)
 LDFLAGS    = $LDFLAGS
 DLLD_FLAVOR  = \$(LD_FLAVOR)
-DLLD       = $DLLD \$(DLLD_FLAVOR)
+DLLD       = \$(LIBTOOL) --mode=link $DLLD \$(DLLD_FLAVOR)
 DLLDFLAGS  = $DLLDFLAGS
 EXTRADLLDFLAGS = $EXTRADLLDFLAGS
 RUNTEST    = $RUNTEST
@@ -205,18 +194,12 @@ GPTESTOPT  = $GPTESTOPT
 #the following line
 #GMPO2 = \$(GMP)/sparcv9.o
 
-_O	   = .o
-_A	   = .a
+_O	   = .lo
+_A	   = .la
 LIB_PREFIX = $lib_prefix
 DLLIB_PREFIX = $dllib_prefix
-LIBPARI_BASE = $libpari_base
-LIBPARI      = \$(LIB_PREFIX)pari
-DLLIBPARI    = \$(DLLIB_PREFIX)pari
-LIBPARI_STA  = \$(LIBPARI)\$(_A)
-LIBPARI_SO   = \$(DLLIBPARI).$DLSUFFIX
-SOLIBPARI    = \$(DLLIB_PREFIX)\$(LIBPARI_BASE).$DLSUFFIX
-LIBPARI_DYN   = \$(SOLIBPARI)$sodest
-LIBPARI_SONAME= \$(SOLIBPARI)$soname
+LIBPARI_BASE = $eibpari_base
+LIBPARI      = \$(LIB_PREFIX)$libpari_base\$(_A)
 DL_DFLT_NAME = $DL_DFLT_NAME
 
 LD_INSTALL_NAME  = $ld_install_name
@@ -276,7 +259,7 @@ QTINC      = $QTINC
 QTLIB      = $QTLIB
 PLOTCFLAGS = $PLOTCFLAGS
 PLOTLIBS   = $PLOTLIBS
-CXX        = g++
+CXX        = \$(LIBTOOL) --mode=compile $CXX
 
 TOPLDDYN   = "$TOP/$objdir"
 # Description system
@@ -295,21 +278,15 @@ TESTS  = $test_extra
 
 dft: $dfttarget ../gp$suffix$exe_suff $libdft
 
-gp: gp-$dft ../gp$suffix$exe_suff $libdft
-
-../gp$suffix$exe_suff: gp-$dft$exe_suff
-	-\$(RM) \$@
-	-\$(LN) $ln_objdir/gp-$dft$exe_suff \$@
-
-all: $exec lib-sta
+gp: \$(OBJSGP) \$(LIBPARI)
+	\$(RM) \$@
+	\$(LD) -o \$@ \$(LDFLAGS) \$(OBJSGP) \$(RUNPTH_FINAL) \$(PLOTLIBS) \$(LIBS) \$(RLLIBS) \$(LIBPARI)
 
-lib-sta: \$(LIBPARI_STA)
-lib-dyn: \$(LIBPARI_DYN)
+all: gp \$(LIBPARI)
+lib: \$(LIBPARI)
 
-\$(LIBPARI_STA): $add_funclist \$(OBJS)
-	-\$(RM) \$@
-	\$(AR) r \$@ \$(OBJS)
-	-\$(RANLIB) \$@
+\$(LIBPARI):\$(OBJS)
+	\$(LD) -o \$@ \$(OBJS) -rpath \$(PREFIX)/lib \$(GMPLIBS) --version-info 0:0
 
 kerntest\$(_O): $src/test/kerntest.c
 	\$(CC) -c -I$src/language \$(CPPFLAGS) \$(CFLAGS) -o \$@ $src/test/kerntest.c
@@ -341,11 +318,6 @@ tune-dyn: tune\$(_O) \$(LIBPARI_DYN)
 tune-sta: tune\$(_O) \$(LIBPARI_STA)
 	\$(LD) \$(LDFLAGS) \$(RUNPTH) -o \$@ \$< \$(GMPOBJS) ./\$(LIBPARI_STA) \$(STA_LIBS)
 
-gp-sta$exe_suff: $add_funclist \$(OBJS) \$(OBJSGP) \$(EXPORT_EXE)
-	\$(RM) \$@
-	\$(LD) -o \$@ \$(LDFLAGS) \$(OBJS) \$(OBJSGP) \$(RUNPTH) \$(RLLIBS) \$(PLOTLIBS) \$(STA_LIBS) \$(EXPORT_EXE)
-	$postconfig gp-sta$exe_suff
-
 clean_pari_ps::
 	@-\$(RM) pari.ps
 cleantest:
@@ -372,9 +344,9 @@ clean: cleanall
 .headers: $HEADERS
 	@touch \$@
 
-install-nodata: install-lib-$dft install-include install-bin install-man install-misc install-examples install-cfg
+install-nodata: install-lib install-include install-bin install-man install-misc install-examples install-cfg
 
-install: install-doc install-nodata install-data
+install: install-nodata install-data
 
 install-include:
 	-mkdir -p \$(INCLUDEDIR)/pari
@@ -385,37 +357,19 @@ install-include:
 	-\$(RM) \$(INCLUDEDIR)/pari/genpari.h
 	-\$(LN) pari.h \$(INCLUDEDIR)/pari/genpari.h
 
-install-bin: install-bin-$dft
-
-install-bin-dyn: gp-dyn$exe_suff install-lib-dyn
-	-mkdir -p \$(BINDIR)
-	-\$(RM) \$(BINDIR)/gp-$version$exe_suff \$(BINDIR)/gp$exe_suff
-	\$(LD) -o \$(BINDIR)/gp-$version$exe_suff -L\$(LIBDIR) \$(LDFLAGS) \$(OBJSGP) \$(RUNPTH_FINAL) \$(LDDYN) \$(RLLIBS) \$(PLOTLIBS) \$(LIBS)
-	-\$(STRIP) \$(STRIPFLAGS) \$(BINDIR)/gp-$version$exe_suff
-	-cd \$(BINDIR); $postconfig gp-$version$exe_suff
-	-\$(LN) gp-$version$exe_suff \$(BINDIR)/gp$exe_suff
-
-install-bin-sta: gp-sta$exe_suff
+install-bin: gp
 	-mkdir -p \$(BINDIR)
-	-\$(RM) \$(BINDIR)/gp-$version$exe_suff \$(BINDIR)/gp$exe_suff
-	\$(INSTALL_PROGRAM) gp-sta$exe_suff \$(BINDIR)/gp-$version$exe_suff
-	-\$(LN) gp-$version$exe_suff \$(BINDIR)/gp$exe_suff
-# Can't strip it if we want install() to work on OSF.
-#	-\$(STRIP) \$(STRIPFLAGS)  \$(BINDIR)/gp-$version
-	-cd \$(BINDIR); $postconfig gp-$version$exe_suff
+	\$(LIBTOOL) --mode=install \$(INSTALL_PROGRAM) gp$exe_suff \$(BINDIR)/gp-$version$exe_suff
 
 install-man::
 	-mkdir -p \$(MANDIR)
 	-\$(RM) \$(MANDIR)/pari.1 \$(MANDIR)/gp.1 \$(MANDIR)/gp-$version.1
-	\$(INSTALL_DATA) $doc/gphelp.1 \$(MANDIR)
 	\$(INSTALL_DATA) $doc/gp.1 \$(MANDIR)/gp-$version.1
 	-\$(LN) gp.1 \$(MANDIR)/pari.1
 	-\$(LN) gp-$version.1 \$(MANDIR)/gp.1
 
 install-misc:
 	-mkdir -p \$(MISCDIR) \$(BINDIR)
-	\$(INSTALL_PROGRAM) $misc/tex2mail \$(BINDIR)
-	\$(INSTALL_DATA) $doc/tex2mail.1 \$(MANDIR)
 	\$(INSTALL_DATA) $misc/README    \$(MISCDIR)
 	\$(INSTALL_DATA) $misc/color.dft \$(MISCDIR)
 	\$(INSTALL_DATA) $misc/gpalias   \$(MISCDIR)
@@ -431,12 +385,11 @@ install-cfg::
 	   \$(INSTALL_DATA) $desc/PARI/822.pm \$(DATADIR)/PARI;\
 	   \$(INSTALL_DATA) $desc/\$(DESC) \$(DATADIR); fi
 
-install-doc: install-docdvi install-doctex
+install-doc: install-docpdf install-doctex
 
 install-doctex:
 	-mkdir -p \$(BINDIR) \$(DOCDIR)
 	-\$(INSTALL_DATA) $doc/translations \$(DOCDIR)
-	-\$(INSTALL_PROGRAM) $doc/gphelp    \$(BINDIR)
 	-cd $doc; \$(MAKE) usersch3.tex
 	-\$(INSTALL_DATA) $doc/appa.tex     \$(DOCDIR)
 	-\$(INSTALL_DATA) $doc/appb.tex     \$(DOCDIR)
@@ -501,23 +454,9 @@ link-data:
 	  done; \
 	fi;
 
-install-lib-sta: \$(LIBPARI_STA)
+install-lib: \$(LIBPARI)
 	-mkdir -p \$(LIBDIR)
-	-\$(RM) \$(LIBDIR)/\$(LIBPARI_STA)
-	\$(INSTALL_DATA) \$(LIBPARI_STA) \$(LIBDIR)/\$(LIBPARI_STA)
-
-install-lib-dyn-base:
-	-mkdir -p \$(LIBDIR)
-	-\$(RM) \$(LIBDIR)/\$(LIBPARI_DYN) \$(LIBDIR)/\$(LIBPARI_SONAME) \$(LIBDIR)/\$(LIBPARI_SO)
-	\$(DLLD_IGNORE)\$(DLLD) -o \$(LIBDIR)/\$(LIBPARI_DYN) \$(DLLDFLAGS) \$(OBJS) \$(EXTRADLLDFLAGS) \$(DYN_LIBS) \$(EXPORT_FILE) \$(LD_INSTALL_NAME)
-	$install_implib
-
-install-lib-dyn-link: install-lib-dyn-base
-	-if test "\$(LIBPARI_DYN)" != "\$(LIBDIR)/\$(LIBPARI_SO)"; then \
-          \$(LN) \$(LIBPARI_DYN) \$(LIBDIR)/\$(LIBPARI_SO); fi
-	-if test "\$(LIBPARI_SONAME)" != "\$(LIBPARI_SO)"; then \
-	  \$(LN) \$(LIBPARI_DYN) \$(LIBDIR)/\$(LIBPARI_SONAME); fi
-install-lib-dyn: \$(LIBPARI_DYN) install-lib-dyn-link
+	\$(LIBTOOL) --mode=install \$(BSD_INSTALL_LIB) \$(LIBPARI) \$(LIBDIR)/
 
 nsis: gp
 	-cd $doc; \$(MAKE) docpdf
@@ -627,11 +566,6 @@ EOT
   fi
   cat >> $file << EOT
 
-gp-dyn$exe_suff: $add_funclist \$(OBJSGP) \$(LIBPARI_DYN) \$(EXPORT_LIB)
-	\$(RM) \$@
-	\$(LD) -o \$@ -L\$(TOPLDDYN) \$(LDFLAGS) \$(OBJSGP) \$(RUNPTH) \$(RLLIBS) \$(LDDYN) \$(PLOTLIBS) \$(LIBS)
-	$postconfig gp-dyn$exe_suff
-
 \$(LIBPARI_DYN): $add_funclist \$(OBJS) \$(EXPORT_FILE)
 	-\$(RM) \$(LIBPARI_DYN)
 	\$(DLLD_IGNORE)\$(DLLD) -o \$(TOPLDDYN)/\$(LIBPARI_DYN) \$(DLLDFLAGS) \$(OBJS) \$(EXTRADLLDFLAGS) \$(DYN_LIBS) \$(EXPORT_FILE)
