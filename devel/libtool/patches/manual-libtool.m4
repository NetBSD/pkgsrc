$NetBSD: manual-libtool.m4,v 1.45 2016/03/10 12:43:48 tnn Exp $

--- libltdl/m4/libtool.m4.orig	2011-10-17 10:17:05.000000000 +0000
+++ libltdl/m4/libtool.m4
@@ -123,7 +123,10 @@ m4_defun([_LT_CC_BASENAME],
     *) break;;
   esac
 done
-cc_basename=`$ECHO "$cc_temp" | $SED "s%.*/%%; s%^$host_alias-%%"`
+# Return the actual command name, not our pkgsrc wrapper name because several
+# decisions are made only based on compiler names
+if test -n "$cc_temp" && new_cc_temp=`$cc_temp --wrappee-name 2>/dev/null`; then :; else new_cc_temp="$cc_temp"; fi
+cc_basename=`$ECHO "X$new_cc_temp" | $Xsed -e 's%.*/%%' -e "s%^$host_alias-%%"`
 ])
 
 
@@ -1098,7 +1101,7 @@ m4_defun([_LT_DARWIN_LINKER_FEATURES],
   _LT_TAGVAR(allow_undefined_flag, $1)="$_lt_dar_allow_undefined"
   case $cc_basename in
      ifort*) _lt_dar_can_shared=yes ;;
-     *) _lt_dar_can_shared=$GCC ;;
+     *) _lt_dar_can_shared=yes ;;
   esac
   if test "$_lt_dar_can_shared" = "yes"; then
     output_verbose_link_cmd=func_echo_all
@@ -1482,7 +1485,7 @@ fi
 
 case $host_os in
   darwin*)
-    lock_old_archive_extraction=yes ;;
+    lock_old_archive_extraction=no ;;	# work around bug #14579
   *)
     lock_old_archive_extraction=no ;;
 esac
@@ -1638,7 +1641,7 @@ AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [d
     lt_cv_sys_max_cmd_len=8192;
     ;;
 
-  netbsd* | freebsd* | openbsd* | darwin* | dragonfly*)
+  netbsd* | freebsd* | openbsd* | mirbsd* | darwin* | dragonfly*)
     # This has been around since 386BSD, at least.  Likely further.
     if test -x /sbin/sysctl; then
       lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
@@ -2468,7 +2471,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd* | dragonfly*)
+freebsd*)
   # DragonFly does not have aout.  When/if they implement a new
   # versioning mechanism, adjust this.
   if test -x /usr/bin/objformat; then
@@ -2482,7 +2485,7 @@ freebsd* | dragonfly*)
   version_type=freebsd-$objformat
   case $version_type in
     freebsd-elf*)
-      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext} $libname${shared_ext}'
+      library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
       need_version=no
       need_lib_prefix=no
       ;;
@@ -2505,13 +2508,24 @@ freebsd* | dragonfly*)
     shlibpath_overrides_runpath=no
     hardcode_into_libs=yes
     ;;
-  *) # from 4.6 on, and DragonFly
+  *) # from 4.6 on
     shlibpath_overrides_runpath=yes
     hardcode_into_libs=yes
     ;;
   esac
   ;;
 
+dragonfly*)
+  version_type=linux
+  need_version=no
+  need_lib_prefix=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=no
+  hardcode_into_libs=yes
+  ;;
+
 gnu*)
   version_type=linux # correct to gnu/linux during the next big refactor
   need_lib_prefix=no
@@ -2599,12 +2613,7 @@ interix[[3-9]]*)
 irix5* | irix6* | nonstopux*)
   case $host_os in
     nonstopux*) version_type=nonstopux ;;
-    *)
-	if test "$lt_cv_prog_gnu_ld" = yes; then
-		version_type=linux # correct to gnu/linux during the next big refactor
-	else
-		version_type=irix
-	fi ;;
+    *) version_type=irix ;;
   esac
   need_lib_prefix=no
   need_version=no
@@ -2684,19 +2693,36 @@ linux* | k*bsd*-gnu | kopensolaris*-gnu)
   dynamic_linker='GNU/Linux ld.so'
   ;;
 
+midnightbsd*)
+  version_type=linux
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}${versuffix2} ${libname}${release}${shared_ext} $libname${shared_ext}'
+  finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=yes
+  hardcode_into_libs=yes
+  ;;
+
+mirbsd*)
+  version_type=linux
+  sys_lib_search_path_spec="/usr/lib"
+  sys_lib_dlsearch_path_spec="/usr/lib"
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}${versuffix2} ${libname}${shared_ext}${versuffix2}'
+  finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
+  shlibpath_var=LD_LIBRARY_PATH
+  shlibpath_overrides_runpath=yes
+  ;;
+
 netbsd*)
-  version_type=sunos
+  version_type=linux
   need_lib_prefix=no
   need_version=no
-  if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
-    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
-    finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
-    dynamic_linker='NetBSD (a.out) ld.so'
-  else
-    library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
-    soname_spec='${libname}${release}${shared_ext}$major'
-    dynamic_linker='NetBSD ld.elf_so'
-  fi
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  dynamic_linker='NetBSD ld.elf_so'
   shlibpath_var=LD_LIBRARY_PATH
   shlibpath_overrides_runpath=yes
   hardcode_into_libs=yes
@@ -2722,7 +2748,7 @@ newsos6)
   ;;
 
 openbsd*)
-  version_type=sunos
+  version_type=linux
   sys_lib_dlsearch_path_spec="/usr/lib"
   need_lib_prefix=no
   # Some older versions of OpenBSD (3.3 at least) *do* need versioned libs.
@@ -2730,7 +2756,7 @@ openbsd*)
     openbsd3.3 | openbsd3.3.*)	need_version=yes ;;
     *)				need_version=no  ;;
   esac
-  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
@@ -3289,12 +3315,19 @@ linux* | k*bsd*-gnu | kopensolaris*-gnu)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
+midnightbsd*)
+  # might to use match_pattern like MirBSD, but there is no well-defined
+  # naming scheme for libraries yet, as the current one is deprecated, and
+  # the new one in a state of flux especially between mports and MirPorts
+  lt_cv_deplibs_check_method=pass_all
+  ;;
+
+mirbsd*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|\.so|_pic\.a)$'
+  ;;
+
 netbsd*)
-  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
-    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
-  else
-    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
-  fi
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
   ;;
 
 newos6*)
@@ -3304,7 +3337,7 @@ newos6*)
   ;;
 
 *nto* | *qnx*)
-  lt_cv_deplibs_check_method=pass_all
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|S\.a)$'
   ;;
 
 openbsd*)
@@ -3651,7 +3684,7 @@ osf*)
   symcode='[[BCDEGQRST]]'
   ;;
 solaris*)
-  symcode='[[BDRT]]'
+  symcode='[[BCDRT]]'
   ;;
 sco3.2v5*)
   symcode='[[DT]]'
@@ -3913,9 +3946,15 @@ m4_if([$1], [CXX], [
 	[_LT_TAGVAR(lt_prog_compiler_pic, $1)='-DDLL_EXPORT'])
       ;;
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)=''
+      ;;
+    *mint*)
+      # FreeMiNT does not support shared libraries at all
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
       ;;
     *djgpp*)
       # DJGPP does not support shared libraries at all
@@ -3994,6 +4033,9 @@ m4_if([$1], [CXX], [
 	    ;;
 	esac
 	;;
+      mint*)
+	# FreeMiNT uses GNU C++
+	;;
       freebsd* | dragonfly*)
 	# FreeBSD uses GNU C++
 	;;
@@ -4232,9 +4274,16 @@ m4_if([$1], [CXX], [
       ;;
 
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)=''
+      ;;
+
+    *mint*)
+      # FreeMiNT does not support shared libraries at all
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
       ;;
 
     haiku*)
@@ -4262,6 +4311,13 @@ m4_if([$1], [CXX], [
       # Instead, we relocate shared libraries at runtime.
       ;;
 
+    mint*)
+      # Just because we use GCC doesn't mean we suddenly get shared libraries
+      # on systems that don't support them.
+      _LT_TAGVAR(lt_prog_compiler_can_build_shared, $1)=no
+      enable_shared=no
+      ;;
+
     msdosdjgpp*)
       # Just because we use GCC doesn't mean we suddenly get shared libraries
       # on systems that don't support them.
@@ -4415,6 +4471,15 @@ m4_if([$1], [CXX], [
       esac
       ;;
 
+    mirbsd*)
+      case $cc_basename in
+      # pkgsrc f77 is f2c, which uses gcc underneath.
+      f77*)
+	_LT_TAGVAR(lt_prog_compiler_wl, $1)='-Wl,'
+	;;
+      esac
+      ;;
+
     newsos6)
       _LT_TAGVAR(lt_prog_compiler_pic, $1)='-KPIC'
       _LT_TAGVAR(lt_prog_compiler_static, $1)='-Bstatic'
@@ -4490,6 +4555,9 @@ m4_if([$1], [CXX], [
 ])
 case $host_os in
   # For platforms which do not support PIC, -DPIC is meaningless:
+  mint*)
+    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+    ;;
   *djgpp*)
     _LT_TAGVAR(lt_prog_compiler_pic, $1)=
     ;;
@@ -4861,16 +4929,29 @@ _LT_EOF
       fi
       ;;
 
-    netbsd*)
-      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
-	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
-	wlarc=
+    mirbsd*)
+      if test -f /usr/libexec/ld.so; then
+	_LT_TAGVAR(hardcode_direct, $1)=yes
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-retain-symbols-file,$export_symbols'
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
       else
-	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
-	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+	_LT_TAGVAR(ld_shlibs, $1)=no
       fi
       ;;
 
+    netbsd*)
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      output_verbose_link_cmd=func_echo_all
+      ;;
+
     solaris*)
       if $LD -v 2>&1 | $GREP 'BFD 2\.8' > /dev/null; then
 	_LT_TAGVAR(ld_shlibs, $1)=no
@@ -5342,15 +5423,28 @@ _LT_EOF
       _LT_TAGVAR(link_all_deplibs, $1)=yes
       ;;
 
-    netbsd*)
-      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
-	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'  # a.out
+    mirbsd*)
+     if test -f /usr/libexec/ld.so; then
+	_LT_TAGVAR(hardcode_direct, $1)=yes
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	_LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file,$export_symbols -o $lib'
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	_LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+	_LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
       else
-	_LT_TAGVAR(archive_cmds, $1)='$LD -shared -o $lib $libobjs $deplibs $linker_flags'      # ELF
+	_LT_TAGVAR(ld_shlibs, $1)=no
       fi
-      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      ;;
+
+    netbsd*)
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
       _LT_TAGVAR(hardcode_direct, $1)=yes
       _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      output_verbose_link_cmd=func_echo_all
       ;;
 
     newsos6)
@@ -5362,6 +5456,11 @@ _LT_EOF
       ;;
 
     *nto* | *qnx*)
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
     openbsd*)
@@ -5819,9 +5918,7 @@ m4_defun([_LT_LANG_CXX_CONFIG],
 [m4_require([_LT_FILEUTILS_DEFAULTS])dnl
 m4_require([_LT_DECL_EGREP])dnl
 m4_require([_LT_PATH_MANIFEST_TOOL])dnl
-if test -n "$CXX" && ( test "X$CXX" != "Xno" &&
-    ( (test "X$CXX" = "Xg++" && `g++ -v >/dev/null 2>&1` ) ||
-    (test "X$CXX" != "Xg++"))) ; then
+if test -n "$CXX" && test "X$CXX" != "Xno" ; then
   AC_PROG_CXXCPP
 else
   _lt_caught_CXX_error=yes
@@ -6538,6 +6635,22 @@ if test "$_lt_caught_CXX_error" != yes; 
         _LT_TAGVAR(ld_shlibs, $1)=no
 	;;
 
+      mirbsd*)
+	if test -f /usr/libexec/ld.so; then
+	  _LT_TAGVAR(hardcode_direct, $1)=yes
+	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	  _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+	  _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags -o $lib'
+	  _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-retain-symbols-file,$export_symbols -o $lib'
+	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	  _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+	  _LT_TAGVAR(whole_archive_flag_spec, $1)="$wlarc"'--whole-archive$convenience '"$wlarc"'--no-whole-archive'
+	  output_verbose_link_cmd='echo'
+	else
+	  _LT_TAGVAR(ld_shlibs, $1)=no
+	fi
+	;;
+
       mvs*)
         case $cc_basename in
           cxx*)
@@ -6552,15 +6665,13 @@ if test "$_lt_caught_CXX_error" != yes; 
 	;;
 
       netbsd*)
-        if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
-	  _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
-	  wlarc=
-	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-	  _LT_TAGVAR(hardcode_direct, $1)=yes
-	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
-	fi
-	# Workaround some broken pre-1.5 toolchains
-	output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+	_LT_TAGVAR(ld_shlibs, $1)=yes
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	_LT_TAGVAR(hardcode_direct, $1)=yes
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	output_verbose_link_cmd=func_echo_all
 	;;
 
       *nto* | *qnx*)
@@ -6739,27 +6850,14 @@ if test "$_lt_caught_CXX_error" != yes; 
 	    # GNU C++ compiler with Solaris linker
 	    if test "$GXX" = yes && test "$with_gnu_ld" = no; then
 	      _LT_TAGVAR(no_undefined_flag, $1)=' ${wl}-z ${wl}defs'
-	      if $CC --version | $GREP -v '^2\.7' > /dev/null; then
-	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
-	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
-		  $CC -shared $pic_flag -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
-
-	        # Commands to make compiler produce verbose output that lists
-	        # what "hidden" libraries, object files and flags are used when
-	        # linking a shared library.
-	        output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
-	      else
-	        # g++ 2.7 appears to require `-G' NOT `-shared' on this
-	        # platform.
-	        _LT_TAGVAR(archive_cmds, $1)='$CC -G -nostdlib $LDFLAGS $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
-	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
-		  $CC -G -nostdlib ${wl}-M $wl$lib.exp -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
-
-	        # Commands to make compiler produce verbose output that lists
-	        # what "hidden" libraries, object files and flags are used when
-	        # linking a shared library.
-	        output_verbose_link_cmd='$CC -G $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
-	      fi
+	      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags ${wl}-h $wl$soname -o $lib'
+	      _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
+		$CC -shared $pic_flag ${wl}-M $wl$lib.exp $wl-h $wl$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
+
+	      # Commands to make compiler produce verbose output that lists
+	      # what "hidden" libraries, object files and flags are used when
+	      # linking a shared library.
+	      output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP -v "^Configured with:" | $GREP "\-L"'
 
 	      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-R $wl$libdir'
 	      case $host_os in
@@ -6995,13 +7093,11 @@ if AC_TRY_EVAL(ac_compile); then
     case ${prev}${p} in
 
     -L* | -R* | -l*)
-       # Some compilers place space between "-{L,R}" and the path.
-       # Remove the space.
-       if test $p = "-L" ||
-          test $p = "-R"; then
-	 prev=$p
-	 continue
-       fi
+       # Some compilers place space between "-{L,R,l}" and the path or
+       # library.  Remove the space.
+       case $p in
+       -L|-R|-l) prev=$p; continue ;;
+       esac
 
        # Expand the sysroot to ease extracting the directories later.
        if test -z "$prev"; then
