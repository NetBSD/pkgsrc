$NetBSD: patch-rts_ghc.mk,v 1.5.10.1 2016/05/23 04:57:18 bsiegert Exp $

This is pkgsrc specific:

Install libffi.{a,la} too, so that the plist framework can deal with
.so name being different between platforms. Note that
"libffi$(soext)*" matches to libffi.{so,so.6,so.6.0} but not to
libffi.6.dylib so the pattern must be corrected to "libffi*$(soext)*",
otherwise libtool-expand will emit the following error on Mach-O
platforms:

  libtool-expand: `lib/ghc-7.6.3/libffi.6.dylib' was not found

For what it's worth, this ain't the right way to install libtool
libraries. They should always be installed by running
"libtool --mode=install install -c foo.la /path/to/destination", which
can't be achieved without a major refactoring of the GHC build system.
And for that matter, GHC shouldn't install a local copy of libffi in
the first place. In fact GHC 7.8 seems to have a configure option
"--with-system-libffi" so we can hopefully remove this rather
unpleasant patch in the future.

--- rts/ghc.mk.orig	2013-04-18 21:22:47.000000000 +0000
+++ rts/ghc.mk
@@ -112,10 +112,11 @@ $(rts_ffi_objs_stamp): $(libffi_STATIC_L
 
 # This is a little hacky. We don't know the SO version, so we only
 # depend on libffi.so, but copy libffi.so*
-rts/dist/build/libffi$(soext): libffi/build/inst/lib/libffi$(soext)
-	cp libffi/build/inst/lib/libffi$(soext)* rts/dist/build
+rts/dist/build/libffi$(soext): libffi/build/inst${ghclibdir}/libffi$(soext)
+	cp libffi/build/inst${ghclibdir}/libffi*$(soext)* rts/dist/build
+	cp libffi/build/inst${ghclibdir}/libffi.*a rts/dist/build
 
-rts/dist/build/$(LIBFFI_DLL): libffi/build/inst/bin/$(LIBFFI_DLL)
+rts/dist/build/$(LIBFFI_DLL): libffi/build/inst${prefix}/bin/$(LIBFFI_DLL)
 	cp $< $@
 endif
 
@@ -185,7 +186,7 @@ else
 $$(rts_$1_LIB) : $$(rts_$1_OBJS) $$(rts_$1_DTRACE_OBJS) rts/libs.depend rts/dist/build/libffi$$(soext)
 	"$$(RM)" $$(RM_OPTS) $$@
 	"$$(rts_dist_HC)" -package-name rts -shared -dynamic -dynload deploy \
-	  -no-auto-link-packages -Lrts/dist/build -lffi `cat rts/libs.depend` $$(rts_$1_OBJS) \
+	  -no-auto-link-packages -Lrts/dist/build -optl -Wl,-rpath,${ghclibdir} -lffi `cat rts/libs.depend` $$(rts_$1_OBJS) \
 	  $$(rts_$1_DTRACE_OBJS) -o $$@
 ifeq "$$(darwin_HOST_OS)" "1"
 	# Ensure library's install name is correct before anyone links with it.
@@ -509,7 +510,8 @@ endif
 # installing
 
 INSTALL_LIBS += $(ALL_RTS_LIBS)
-INSTALL_LIBS += $(wildcard rts/dist/build/libffi$(soext)*)
+INSTALL_LIBS += $(wildcard rts/dist/build/libffi*$(soext)*)
+INSTALL_LIBS += $(wildcard rts/dist/build/libffi.*a)
 INSTALL_LIBS += $(wildcard rts/dist/build/$(LIBFFI_DLL))
 
 install: install_libffi_headers
