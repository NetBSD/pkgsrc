$NetBSD: manual-libtool.m4,v 1.18 2006/01/30 22:19:56 tv Exp $

--- libtool.m4.orig	2005-12-18 16:53:17.000000000 -0500
+++ libtool.m4
@@ -392,11 +392,11 @@ else
 
   if test "X$echo" = Xecho; then
     # We didn't find a better echo, so look for alternatives.
-    if test "X`(print -r '\t') 2>/dev/null`" = 'X\t' &&
+    if test "X`(print -r - '\t') 2>/dev/null`" = 'X\t' &&
        echo_testing_string=`(print -r "$echo_test_string") 2>/dev/null` &&
        test "X$echo_testing_string" = "X$echo_test_string"; then
       # This shell has a builtin print -r that does the trick.
-      echo='print -r'
+      echo='print -r -'
     elif (test -f /bin/ksh || test -f /bin/ksh$ac_exeext) &&
 	 test "X$CONFIG_SHELL" != X/bin/ksh; then
       # If we have ksh, try running configure again with it.
@@ -1289,6 +1289,7 @@ beos*)
 bsdi[[45]]*)
   version_type=linux
   need_version=no
+  need_lib_prefix=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
   soname_spec='${libname}${release}${shared_ext}$major'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig $libdir'
@@ -1414,15 +1415,16 @@ freebsd* | dragonfly*)
     *) objformat=elf ;;
     esac
   fi
-  version_type=freebsd-$objformat
-  case $version_type in
-    freebsd-elf*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
+  version_type=linux
+  case $objformat in
+    elf*)
+      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
+      soname_spec='${libname}${release}${shared_ext}$major'
       need_version=no
       need_lib_prefix=no
       ;;
-    freebsd-*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix $libname${shared_ext}$versuffix'
+    *)
+      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
       need_version=yes
       ;;
   esac
@@ -1518,12 +1520,7 @@ interix3*)
 irix5* | irix6* | nonstopux*)
   case $host_os in
     nonstopux*) version_type=nonstopux ;;
-    *)
-	if test "$lt_cv_prog_gnu_ld" = yes; then
-		version_type=linux
-	else
-		version_type=irix
-	fi ;;
+    *) version_type=irix ;;
   esac
   need_lib_prefix=no
   need_version=no
@@ -1600,11 +1597,11 @@ knetbsd*-gnu)
   ;;
 
 netbsd*)
-  version_type=sunos
+  version_type=linux
   need_lib_prefix=no
   need_version=no
   if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
-    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
     finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
     dynamic_linker='NetBSD (a.out) ld.so'
   else
@@ -1635,7 +1632,7 @@ nto-qnx*)
   ;;
 
 openbsd*)
-  version_type=sunos
+  version_type=linux
   sys_lib_dlsearch_path_spec="/usr/lib"
   need_lib_prefix=no
   # Some older versions of OpenBSD (3.3 at least) *do* need versioned libs.
@@ -1643,7 +1640,7 @@ openbsd*)
     openbsd3.3 | openbsd3.3.*) need_version=yes ;;
     *)                         need_version=no  ;;
   esac
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
@@ -1832,9 +1829,7 @@ if test -f "$ltmain" && test -n "$tagnam
 
       case $tagname in
       CXX)
-	if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-	    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
-	    (test "X$CXX" != "Xg++"))) ; then
+        if test -n "$CXX" && test "X$CXX" != "Xno"; then
 	  AC_LIBTOOL_LANG_CXX_CONFIG
 	else
 	  tagname=""
@@ -2580,22 +2575,10 @@ AC_DEFUN([AC_LIBTOOL_CXX],
 # ---------------
 AC_DEFUN([_LT_AC_LANG_CXX],
 [AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 _LT_AC_SHELL_INIT([tagnames=${tagnames+${tagnames},}CXX])
 ])# _LT_AC_LANG_CXX
 
-# _LT_AC_PROG_CXXCPP
-# ------------------
-AC_DEFUN([_LT_AC_PROG_CXXCPP],
-[
-AC_REQUIRE([AC_PROG_CXX])
-if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
-    (test "X$CXX" != "Xg++"))) ; then
-  AC_PROG_CXXCPP
-fi
-])# _LT_AC_PROG_CXXCPP
-
 # AC_LIBTOOL_F77
 # --------------
 # enable support for Fortran 77 libraries
@@ -2732,7 +2715,7 @@ AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG], [
 AC_DEFUN([_LT_AC_LANG_CXX_CONFIG],
 [AC_LANG_PUSH(C++)
 AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 
 _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
 _LT_AC_TAGVAR(allow_undefined_flag, $1)=
@@ -3080,7 +3063,7 @@ case $host_os in
           _LT_AC_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring'
           _LT_AC_TAGVAR(module_cmds, $1)='$CC $allow_undefined_flag -o $lib -bundle $libobjs $deplibs$compiler_flags'
           # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin lds
-          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}$rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC $allow_undefined_flag  -o $lib -bundle $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           ;;
        *)
@@ -3377,14 +3360,29 @@ case $host_os in
     ;;
   netbsd*)
     if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
+      # a.out is quite broken and goes directly to ld
       _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
       wlarc=
+      # Determine if we need to override the c++rt0 that is
+      # picked up by analysing output_verbose_link_cmds
+      if test -f ${PREFIX}/lib/c++rt0/c++rt0.o.PIC; then
+        cpprt0_file="${PREFIX}/lib/c++rt0/c++rt0.o.PIC"
+      else
+        cpprt0_file=
+      fi
       _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
       _LT_AC_TAGVAR(hardcode_direct, $1)=yes
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+    elif $CC -dumpspecs | grep -- '-lgcc -lc -lgcc' >/dev/null; then
+      # Workaround some broken pre-1.5 ELF toolchains
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+    else
+      # Modern ELF works sanely as-is
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      output_verbose_link_cmd='echo'
     fi
-    # Workaround some broken pre-1.5 toolchains
-    output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
     ;;
   openbsd2*)
     # C++ shared libraries are fairly broken
@@ -3872,6 +3870,12 @@ interix3*)
   _LT_AC_TAGVAR(postdeps,$1)=
   ;;
 
+netbsd*)
+  if test -n "$cpprt0_file"; then
+    _LT_AC_TAGVAR(predep_objects,$1)=`eval echo $_LT_AC_TAGVAR(predep_objects,$1) | sed -e 's:/usr/lib/c++rt0.o:$cpprt0_file:'`
+  fi
+  ;;
+
 solaris*)
   case $cc_basename in
   CC*)
@@ -4847,9 +4851,11 @@ AC_MSG_CHECKING([for $compiler option to
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'
       ;;
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
     *djgpp*)
       # DJGPP does not support shared libraries at all
@@ -5122,9 +5128,11 @@ AC_MSG_CHECKING([for $compiler option to
       ;;
 
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
 
     interix3*)
@@ -5850,7 +5858,7 @@ _LT_EOF
          _LT_AC_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring'
          _LT_AC_TAGVAR(module_cmds, $1)='$CC $allow_undefined_flag -o $lib -bundle $libobjs $deplibs$compiler_flags'
           # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin lds
-         _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}$rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+         _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC $allow_undefined_flag  -o $lib -bundle $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           ;;
        *)
