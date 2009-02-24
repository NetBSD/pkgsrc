$NetBSD: manual-libtool.m4,v 1.24 2009/02/24 10:13:26 abs Exp $

Local pkgsrc changes:
- override the basename to point to the actual backend compiler,
  critical e.g. on Solaris
- portability fixes for print on Interix
- override for shlib naming policy on various platforms
- QNX support
- Interix3 support
- disable static linkage on OS X by default

--- libtool.m4.orig	2008-02-01 16:26:47.000000000 +0000
+++ libtool.m4	2009-02-21 23:20:30.000000000 +0000
@@ -249,7 +249,10 @@
     *) break;;
   esac
 done
-cc_basename=`$echo "X$cc_temp" | $Xsed -e 's%.*/%%' -e "s%^$host_alias-%%"`
+# Return the actual command name, not our pkgsrc wrapper name because several
+# decisions are made only based on compiler names
+new_cc_temp=`$cc_temp --wrappee-name 2>/dev/null` || new_cc_temp="$cc_temp"
+cc_basename=`$echo "X$new_cc_temp" | $Xsed -e 's%.*/%%' -e "s%^$host_alias-%%"`
 ])
 
 
@@ -474,11 +477,11 @@
 
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
@@ -820,6 +823,13 @@
     lt_cv_sys_max_cmd_len=8192;
     ;;
 
+  mint*)
+    # On MiNT we can support fairly large cmd lengths, but it takes
+    # a while to run the tests, so let's restrict it to something
+    # reasonable.
+    lt_cv_sys_max_cmd_len=8192;
+    ;;
+
   amigaos*)
     # On AmigaOS with pdksh, this test takes hours, literally.
     # So we just punt and use a minimum line length of 8192.
@@ -1427,6 +1437,7 @@
 bsdi[[45]]*)
   version_type=linux
   need_version=no
+  need_lib_prefix=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
   soname_spec='${libname}${release}${shared_ext}$major'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig $libdir'
@@ -1525,7 +1536,7 @@
   dynamic_linker=no
   ;;
 
-freebsd* | dragonfly*)
+freebsd*)
   # DragonFly does not have aout.  When/if they implement a new
   # versioning mechanism, adjust this.
   if test -x /usr/bin/objformat; then
@@ -1539,7 +1550,7 @@
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
+      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
       need_version=no
       need_lib_prefix=no
       ;;
@@ -1569,6 +1580,16 @@
   esac
   ;;
 
+dragonfly*)
+  version_type=linux # XXX tv this should be =linux; current selection has problems
+  need_version=no
+  need_lib_prefix=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=no
+  hardcode_into_libs=yes
+  ;;
+
 gnu*)
   version_type=linux
   need_lib_prefix=no
@@ -1637,15 +1658,22 @@
   hardcode_into_libs=yes
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
@@ -1710,11 +1738,11 @@
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
@@ -1739,13 +1767,14 @@
   need_lib_prefix=no
   need_version=no
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major $libname${shared_ext}'
+  dynamic_linker='QNX libc.so'
   soname_spec='${libname}${release}${shared_ext}$major'
   shlibpath_var=LD_LIBRARY_PATH
   shlibpath_overrides_runpath=yes
   ;;
 
 openbsd*)
-  version_type=sunos
+  version_type=linux
   sys_lib_dlsearch_path_spec="/usr/lib"
   need_lib_prefix=no
   # Some older versions of OpenBSD (3.3 at least) *do* need versioned libs.
@@ -1753,7 +1782,7 @@
     openbsd3.3 | openbsd3.3.*) need_version=yes ;;
     *)                         need_version=no  ;;
   esac
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   if test -z "`echo __ELF__ | $CC -E - | grep __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
@@ -1954,9 +1983,7 @@
 
       case $tagname in
       CXX)
-	if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-	    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
-	    (test "X$CXX" != "Xg++"))) ; then
+	if test -n "$CXX" && test "X$CXX" != "Xno" ; then
 	  AC_LIBTOOL_LANG_CXX_CONFIG
 	else
 	  tagname=""
@@ -2475,6 +2502,10 @@
   lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
   ;;
 
+interix3*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|\.a)$'
+  ;;
+
 irix5* | irix6* | nonstopux*)
   case $LD in
   *-32|*"-32 ") libmagic=32-bit;;
@@ -2505,7 +2536,7 @@
   ;;
 
 nto-qnx*)
-  lt_cv_deplibs_check_method=unknown
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|S\.a)$'
   ;;
 
 openbsd*)
@@ -2712,21 +2743,10 @@
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
 
 # AC_LIBTOOL_F77
 # --------------
@@ -2864,7 +2884,7 @@
 AC_DEFUN([_LT_AC_LANG_CXX_CONFIG],
 [AC_LANG_PUSH(C++)
 AC_REQUIRE([AC_PROG_CXX])
-AC_REQUIRE([_LT_AC_PROG_CXXCPP])
+AC_REQUIRE([AC_PROG_CXXCPP])
 
 _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
 _LT_AC_TAGVAR(allow_undefined_flag, $1)=
@@ -3350,6 +3370,16 @@
     _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
     _LT_AC_TAGVAR(archive_expsym_cmds, $1)='sed "s,^,_," $export_symbols >$output_objdir/$soname.expsym~$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file,$output_objdir/$soname.expsym ${wl}--image-base,`expr ${RANDOM-$$} % 4096 / 2 \* 262144 + 1342177280` -o $lib'
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
       CC*)
@@ -3503,14 +3533,29 @@
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
-    fi
-    # Workaround some broken pre-1.5 toolchains
     output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+    elif $CC -dumpspecs | grep -- '-lgcc -lc -lgcc' >/dev/null; then
+      # Workaround some broken pre-1.5 ELF toolchains
+      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | grep conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+    else
+      # Modern ELF works sanely as-is
+      _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      output_verbose_link_cmd='echo'
+    fi
     ;;
   openbsd2*)
     # C++ shared libraries are fairly broken
@@ -3823,6 +3868,11 @@
     # FIXME: insert proper C++ library support
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
+  nto-qnx*)
+    _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+    _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+    output_verbose_link_cmd='echo'
+    ;;
   *)
     # FIXME: insert proper C++ library support
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
@@ -3985,6 +4035,21 @@
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
@@ -5033,9 +5098,15 @@
 	[_LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
       ;;
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
+      ;;
+    *mint*)
+      # FreeMiNT does not support shared libraries at all
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
       ;;
     *djgpp*)
       # DJGPP does not support shared libraries at all
@@ -5061,6 +5132,10 @@
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
@@ -5107,6 +5182,9 @@
 	    ;;
 	esac
 	;;
+      mint*)
+	# FreeMiNT uses GNU C++
+	;;
       freebsd* | dragonfly*)
 	# FreeBSD uses GNU C++
 	;;
@@ -5139,6 +5217,8 @@
 	# This is c89, which is MS Visual C++ (no shared libs)
 	# Anyone wants to do a port?
 	;;
+      interix3*)
+	;;
       irix5* | irix6* | nonstopux*)
 	case $cc_basename in
 	  CC*)
@@ -5278,6 +5358,8 @@
 	;;
       vxworks*)
 	;;
+      nto-qnx*)
+	;;
       *)
 	_LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
 	;;
@@ -5319,9 +5401,11 @@
       ;;
 
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_AC_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
 
     interix[[3-9]]*)
@@ -5329,6 +5413,13 @@
       # Instead, we relocate shared libraries at runtime.
       ;;
 
+    mint*)
+      # Just because we use GCC doesn't mean we suddenly get shared libraries
+      # on systems that don't support them.
+      _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      enable_shared=no
+      ;;
+
     msdosdjgpp*)
       # Just because we use GCC doesn't mean we suddenly get shared libraries
       # on systems that don't support them.
@@ -5355,6 +5446,11 @@
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
@@ -5510,6 +5606,10 @@
       _LT_AC_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
       ;;
 
+    nto-qnx*)
+      _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)='-fPIC'
+      ;;
+
     *)
       _LT_AC_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
       ;;
@@ -5534,6 +5634,9 @@
 fi
 case $host_os in
   # For platforms which do not support PIC, -DPIC is meaningless:
+  mint*)
+    _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
+    ;;
   *djgpp*)
     _LT_AC_TAGVAR(lt_prog_compiler_pic, $1)=
     ;;
@@ -5791,6 +5894,17 @@
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
@@ -5856,6 +5970,11 @@
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
+    nto-qnx*)
+       _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+       _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+       ;;
+
     *)
       if $LD --help 2>&1 | grep ': supported targets:.* elf' > /dev/null; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
@@ -6210,6 +6329,21 @@
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
@@ -6435,6 +6569,13 @@
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
+    nto-qnx*)
+      _LT_AC_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
     *)
       _LT_AC_TAGVAR(ld_shlibs, $1)=no
       ;;
