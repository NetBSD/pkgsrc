$NetBSD: manual-libtool.m4,v 1.12 2005/01/18 18:51:15 tv Exp $

--- libtool.m4.orig	2004-09-19 08:15:08.000000000 -0400
+++ libtool.m4
@@ -361,11 +361,11 @@ else
 
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
@@ -678,7 +678,7 @@ AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [d
     lt_cv_sys_max_cmd_len=8192;
     ;;
 
-  netbsd* | freebsd* | openbsd* | darwin* )
+  netbsd* | freebsd* | openbsd* | darwin* | dragonfly*)
     # This has been around since 386BSD, at least.  Likely further.
     if test -x /sbin/sysctl; then
       lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
@@ -1201,6 +1201,7 @@ beos*)
 bsdi[[45]]*)
   version_type=linux
   need_version=no
+  need_lib_prefix=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
   soname_spec='${libname}${release}${shared_ext}$major'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig $libdir'
@@ -1315,16 +1316,17 @@ kfreebsd*-gnu)
   ;;
 
 freebsd*)
+  version_type=linux
   objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
-  version_type=freebsd-$objformat
-  case $version_type in
-    freebsd-elf*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
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
@@ -1344,6 +1346,16 @@ freebsd*)
   esac
   ;;
 
+dragonfly*)
+  version_type=freebsd-elf # XXX tv this should be =linux; current selection has problems
+  need_version=no
+  need_lib_prefix=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=no
+  hardcode_into_libs=yes
+  ;;
+
 gnu*)
   version_type=linux
   need_lib_prefix=no
@@ -1400,15 +1412,22 @@ hpux9* | hpux10* | hpux11*)
   postinstall_cmds='chmod 555 $lib'
   ;;
 
+interix3*)
+  version_type=linux
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  dynamic_linker='Interix 3.x ld.so'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=yes
+  hardcode_into_libs=yes
+  ;;
+
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
@@ -1485,11 +1504,11 @@ knetbsd*-gnu)
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
@@ -1520,10 +1539,10 @@ nto-qnx*)
   ;;
 
 openbsd*)
-  version_type=sunos
+  version_type=linux
   need_lib_prefix=no
   need_version=no
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix2'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
@@ -1688,9 +1707,7 @@ if test -f "$ltmain" && test -n "$tagnam
 
       case $tagname in
       CXX)
-	if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-	    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) || 
-	    (test "X$CXX" != "Xg++"))) ; then
+	if test -n "$CXX" && test "X$CXX" != "Xno"; then
 	  AC_LIBTOOL_LANG_CXX_CONFIG
 	else
 	  tagname=""
@@ -2160,13 +2177,13 @@ darwin* | rhapsody*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-freebsd* | kfreebsd*-gnu)
+freebsd* | kfreebsd*-gnu | dragonfly*)
   if echo __ELF__ | $CC -E - | grep __ELF__ > /dev/null; then
     case $host_cpu in
     i*86 )
       # Not sure whether the presence of OpenBSD here was a mistake.
       # Let's accept both of them until this is cleared up.
-      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD)/i[[3-9]]86 (compact )?demand paged shared library'
+      lt_cv_deplibs_check_method='file_magic (FreeBSD|OpenBSD|DragonFly)/i[[3-9]]86 (compact )?demand paged shared library'
       lt_cv_file_magic_cmd=/usr/bin/file
       lt_cv_file_magic_test_file=`echo /usr/lib/libc.so.*`
       ;;
@@ -2198,6 +2215,10 @@ hpux10.20* | hpux11*)
   esac
   ;;
 
+interix3*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
+  ;;
+
 irix5* | irix6* | nonstopux*)
   case $LD in
   *-32|*"-32 ") libmagic=32-bit;;
@@ -2425,21 +2446,10 @@ AC_DEFUN([AC_LIBTOOL_CXX],
 # ---------------
 AC_DEFUN([_LT_AC_LANG_CXX],
 [AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 _LT_AC_SHELL_INIT([tagnames=${tagnames+${tagnames},}CXX])
 ])# _LT_AC_LANG_CXX
 
-# _LT_AC_PROG_CXXCPP
-# ---------------
-AC_DEFUN([_LT_AC_PROG_CXXCPP],
-[
-AC_REQUIRE([AC_PROG_CXX])
-if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) || 
-    (test "X$CXX" != "Xg++"))) ; then
-  AC_PROG_CXXCPP
-fi
-])# _LT_AC_PROG_CXXCPP
 
 # AC_LIBTOOL_F77
 # --------------
@@ -2604,7 +2614,7 @@ AC_DEFUN([AC_LIBTOOL_LANG_CXX_CONFIG], [
 AC_DEFUN([_LT_AC_LANG_CXX_CONFIG],
 [AC_LANG_PUSH(C++)
 AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 
 _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
 _LT_AC_TAGVAR(allow_undefined_flag, $1)=
@@ -2933,7 +2943,7 @@ case $host_os in
           _LT_AC_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring'
           _LT_AC_TAGVAR(module_cmds, $1)='$CC $allow_undefined_flag -o $lib -bundle $libobjs $deplibs$compiler_flags'
           # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}$rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+          _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj ${wl}-single_module $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC $allow_undefined_flag  -o $lib -bundle $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           ;;
        *)
@@ -2967,7 +2977,7 @@ case $host_os in
   freebsd-elf*)
     _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
     ;;
-  freebsd* | kfreebsd*-gnu)
+  freebsd* | kfreebsd*-gnu | dragonfly*)
     # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
     # conventions
     _LT_AC_TAGVAR(ld_shlibs, $1)=yes
@@ -3091,6 +3101,16 @@ case $host_os in
 	;;
     esac
     ;;
+  interix3*)
+    # Oy, what a hack.
+    # Because shlibs are not compiled -fPIC due to broken code, we must
+    # choose an --image-base.  Otherwise, 0x10000000 will be chosen for
+    # all libraries, leading to runtime relocations -- slow and very
+    # memory consuming.  To do this, we pick a random 256KB-aligned
+    # start address between 0x50000000 and 0x6ffc0000 at link time.
+    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+    _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed s,^,_, $export_symbols >$output_objdir/$soname.exp && $CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$output_objdir/$soname ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+    ;;
   irix5* | irix6*)
     case $cc_basename in
       CC)
@@ -3208,14 +3228,29 @@ case $host_os in
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
@@ -3651,6 +3686,21 @@ if AC_TRY_EVAL(ac_compile); then
     esac
   done
 
+  case "$host_os" in
+  netbsd*)
+    if test -n "$cpprt0_file"; then
+      predep_objects_CXX=`eval echo $predep_objects_CXX | sed -e 's:/usr/lib/c++rt0.o:$cpprt0_file:'`
+    fi
+    ;;
+  interix3*)
+    # Interix installs completely hosed .la files for C++, so rather than
+    # hack all around it, let's just trust "g++" to DTRT.
+    predep_objects_CXX=
+    postdep_objects_CXX=
+    postdeps_CXX=
+    ;;
+  esac
+
   # Clean up.
   rm -f a.out a.exe
 else
@@ -4591,9 +4641,11 @@ AC_MSG_CHECKING([for $compiler option to
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
@@ -4615,6 +4667,10 @@ AC_MSG_CHECKING([for $compiler option to
 	;;
       esac
       ;;
+    interix3*)
+      # Interix 3.0-3.5 -fPIC option generates borked code.
+      # (Instead, shlibs are relocated at runtime.)
+      ;;
     *)
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
       ;;
@@ -4661,7 +4717,7 @@ AC_MSG_CHECKING([for $compiler option to
 	    ;;
 	esac
 	;;
-      freebsd* | kfreebsd*-gnu)
+      freebsd* | kfreebsd*-gnu | dragonfly*)
 	# FreeBSD uses GNU C++
 	;;
       hpux9* | hpux10* | hpux11*)
@@ -4689,6 +4745,8 @@ AC_MSG_CHECKING([for $compiler option to
 	    ;;
 	esac
 	;;
+      interix3*)
+	;;
       irix5* | irix6* | nonstopux*)
 	case $cc_basename in
 	  CC)
@@ -4854,9 +4912,11 @@ AC_MSG_CHECKING([for $compiler option to
       ;;
 
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
 
     msdosdjgpp*)
@@ -4885,6 +4945,11 @@ AC_MSG_CHECKING([for $compiler option to
       esac
       ;;
 
+    interix3*)
+      # Interix 3.0-3.5 -fPIC option generates borked code.
+      # (Instead, shlibs are relocated at runtime.)
+      ;;
+
     *)
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
       ;;
@@ -5187,6 +5252,17 @@ EOF
       fi
       ;;
 
+    interix3*)
+      # Oy, what a hack.
+      # Because shlibs are not compiled -fPIC due to broken code, we must
+      # choose an --image-base.  Otherwise, 0x10000000 will be chosen for
+      # all libraries, leading to runtime relocations -- slow and very
+      # memory consuming.  To do this, we pick a random 256KB-aligned
+      # start address between 0x50000000 and 0x6ffc0000 at link time.
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed s,^,_, $export_symbols >$output_objdir/$soname.exp && $CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$output_objdir/$soname.exp ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      ;;
+
     netbsd*)
       if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
@@ -5477,7 +5553,7 @@ $echo "local: *; };" >> $output_objdir/$
          _LT_AC_TAGVAR(archive_cmds, $1)='$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring'
          _LT_AC_TAGVAR(module_cmds, $1)='$CC $allow_undefined_flag -o $lib -bundle $libobjs $deplibs$compiler_flags'
           # Don't fix this by using the ld -exported_symbols_list flag, it doesn't exist in older darwin ld's
-         _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}$rpath/$soname $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
+         _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC -qmkshrobj $allow_undefined_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-install_name ${wl}`echo $rpath/$soname` $verstring~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           _LT_AC_TAGVAR(module_expsym_cmds, $1)='sed -e "s,#.*,," -e "s,^[    ]*,," -e "s,^\(..*\),_&," < $export_symbols > $output_objdir/${libname}-symbols.expsym~$CC $allow_undefined_flag  -o $lib -bundle $libobjs $deplibs$compiler_flags~nmedit -s $output_objdir/${libname}-symbols.expsym ${lib}'
           ;;
        *)
@@ -5517,7 +5593,7 @@ $echo "local: *; };" >> $output_objdir/$
       ;;
 
     # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
-    freebsd* | kfreebsd*-gnu)
+    freebsd* | kfreebsd*-gnu | dragonfly*)
       _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -o $lib $libobjs $deplibs $compiler_flags'
       _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
       _LT_AC_TAGVAR(hardcode_direct, $1)=yes
@@ -5592,6 +5668,21 @@ $echo "local: *; };" >> $output_objdir/$
       fi
       ;;
 
+    interix3*)
+      # Oy, what a hack.
+      # Because shlibs are not compiled -fPIC due to broken code, we must
+      # choose an --image-base.  Otherwise, 0x10000000 will be chosen for
+      # all libraries, leading to runtime relocations -- slow and very
+      # memory consuming.  To do this, we pick a random 256KB-aligned
+      # start address between 0x50000000 and 0x6ffc0000 at link time.
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed s,^,_, $export_symbols >$output_objdir/$soname.exp && $CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$output_objdir/$soname ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-h,$libdir'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
     irix5* | irix6* | nonstopux*)
       if test "$GCC" = yes; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
