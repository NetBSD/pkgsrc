$NetBSD: manual-libtool.m4,v 1.48 2018/11/13 21:44:42 sevan Exp $

Support mirbsd, midnightbsd, minix.
Handle pkgsrc wrappers.
Fixup output on various OS.

--- m4/libtool.m4.orig	Tue Jan 20 16:15:19 2015
+++ m4/libtool.m4
@@ -117,7 +117,10 @@ func_cc_basename ()
         *) break;;
       esac
     done
-    func_cc_basename_result=`$ECHO "$cc_temp" | $SED "s%.*/%%; s%^$host_alias-%%"`
+    # Return the actual command name, not our pkgsrc wrapper name because several
+    # decisions are made only based on compiler names
+    if test -n "$cc_temp" && new_cc_temp=`$cc_temp --wrappee-name 2>/dev/null`; then :; else new_cc_temp="$cc_temp"; fi
+    func_cc_basename_result=`$ECHO "X$new_cc_temp" | $Xsed -e 's%.*/%%' -e "s%^$host_alias-%%"`
 }
 ])# _LT_PREPARE_CC_BASENAME
 
@@ -141,7 +144,10 @@ cc_basename=$func_cc_basename_result
 # It is okay to use these file commands and assume they have been set
 # sensibly after 'm4_require([_LT_FILEUTILS_DEFAULTS])'.
 m4_defun([_LT_FILEUTILS_DEFAULTS],
-[: ${CP="cp -f"}
+[unset CP
+unset MV
+unset RM
+: ${CP="cp -f"}
 : ${MV="mv -f"}
 : ${RM="rm -f"}
 ])# _LT_FILEUTILS_DEFAULTS
@@ -1120,7 +1126,7 @@ m4_defun([_LT_DARWIN_LINKER_FEATURES],
   _LT_TAGVAR(allow_undefined_flag, $1)=$_lt_dar_allow_undefined
   case $cc_basename in
      ifort*|nagfor*) _lt_dar_can_shared=yes ;;
-     *) _lt_dar_can_shared=$GCC ;;
+     *) _lt_dar_can_shared=yes ;;
   esac
   if test yes = "$_lt_dar_can_shared"; then
     output_verbose_link_cmd=func_echo_all
@@ -1558,7 +1564,7 @@ fi
 
 case $host_os in
   darwin*)
-    lock_old_archive_extraction=yes ;;
+    lock_old_archive_extraction=no ;;	# work around bug #14579
   *)
     lock_old_archive_extraction=no ;;
 esac
@@ -1714,7 +1720,7 @@ AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [dnl
     lt_cv_sys_max_cmd_len=8192;
     ;;
 
-  bitrig* | darwin* | dragonfly* | freebsd* | netbsd* | openbsd*)
+  bitrig* | darwin* | dragonfly* | freebsd* | minix* | netbsd* | openbsd* | mirbsd*)
     # This has been around since 386BSD, at least.  Likely further.
     if test -x /sbin/sysctl; then
       lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
@@ -2655,7 +2661,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd* | dragonfly*)
+freebsd*)
   # DragonFly does not have aout.  When/if they implement a new
   # versioning mechanism, adjust this.
   if test -x /usr/bin/objformat; then
@@ -2700,6 +2706,17 @@ freebsd* | dragonfly*)
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
 haiku*)
   version_type=linux # correct to gnu/linux during the next big refactor
   need_lib_prefix=no
@@ -2777,12 +2794,7 @@ interix[[3-9]]*)
 irix5* | irix6* | nonstopux*)
   case $host_os in
     nonstopux*) version_type=nonstopux ;;
-    *)
-	if test yes = "$lt_cv_prog_gnu_ld"; then
-		version_type=linux # correct to gnu/linux during the next big refactor
-	else
-		version_type=irix
-	fi ;;
+    *) version_type=irix ;;
   esac
   need_lib_prefix=no
   need_version=no
@@ -2887,19 +2899,48 @@ linux* | k*bsd*-gnu | kopensolaris*-gnu | gnu*)
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
+minix*)
+  version_type=linux
+  need_lib_prefix=no
+  need_version=no
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  dynamic_linker='Minix ld.elf_so'
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
-    library_names_spec='$libname$release$shared_ext$versuffix $libname$shared_ext$versuffix'
-    finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
-    dynamic_linker='NetBSD (a.out) ld.so'
-  else
-    library_names_spec='$libname$release$shared_ext$versuffix $libname$release$shared_ext$major $libname$shared_ext'
-    soname_spec='$libname$release$shared_ext$major'
-    dynamic_linker='NetBSD ld.elf_so'
-  fi
+  library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
+  soname_spec='${libname}${release}${shared_ext}$major'
+  dynamic_linker='NetBSD ld.elf_so'
   shlibpath_var=LD_LIBRARY_PATH
   shlibpath_overrides_runpath=yes
   hardcode_into_libs=yes
@@ -2925,7 +2966,7 @@ newsos6)
   ;;
 
 openbsd* | bitrig*)
-  version_type=sunos
+  version_type=linux
   sys_lib_dlsearch_path_spec=/usr/lib
   need_lib_prefix=no
   if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`"; then
@@ -2933,7 +2974,7 @@ openbsd* | bitrig*)
   else
     need_version=yes
   fi
-  library_names_spec='$libname$release$shared_ext$versuffix $libname$shared_ext$versuffix'
+  library_names_spec='$libname$release$shared_ext$versuffix ${libname}${release}${shared_ext}$major ${libname}${shared_ext}'
   finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   shlibpath_overrides_runpath=yes
@@ -3546,14 +3587,21 @@ linux* | k*bsd*-gnu | kopensolaris*-gnu | gnu*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-netbsd*)
-  if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
-    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|_pic\.a)$'
-  else
-    lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
-  fi
+midnightbsd*)
+  # might to use match_pattern like MirBSD, but there is no well-defined
+  # naming scheme for libraries yet, as the current one is deprecated, and
+  # the new one in a state of flux especially between mports and MirPorts
+  lt_cv_deplibs_check_method=pass_all
   ;;
 
+mirbsd*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so\.[[0-9]]+\.[[0-9]]+|\.so|_pic\.a)$'
+  ;;
+
+netbsd* | minix*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
+  ;;
+
 newos6*)
   lt_cv_deplibs_check_method='file_magic ELF [[0-9]][[0-9]]*-bit [[ML]]SB (executable|dynamic lib)'
   lt_cv_file_magic_cmd=/usr/bin/file
@@ -3561,7 +3609,7 @@ newos6*)
   ;;
 
 *nto* | *qnx*)
-  lt_cv_deplibs_check_method=pass_all
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|S\.a)$'
   ;;
 
 openbsd* | bitrig*)
@@ -3931,7 +3979,7 @@ osf*)
   symcode='[[BCDEGQRST]]'
   ;;
 solaris*)
-  symcode='[[BDRT]]'
+  symcode='[[BCDRT]]'
   ;;
 sco3.2v5*)
   symcode='[[DT]]'
@@ -4236,10 +4284,16 @@ m4_if([$1], [CXX], [
       esac
       ;;
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
+    *mint*)
+      # FreeMiNT does not support shared libraries at all
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+      ;;
     *djgpp*)
       # DJGPP does not support shared libraries at all
       _LT_TAGVAR(lt_prog_compiler_pic, $1)=
@@ -4317,6 +4371,9 @@ m4_if([$1], [CXX], [
 	    ;;
 	esac
 	;;
+      mint*)
+	# FreeMiNT uses GNU C++
+	;;
       freebsd* | dragonfly*)
 	# FreeBSD uses GNU C++
 	;;
@@ -4424,7 +4481,7 @@ m4_if([$1], [CXX], [
 	    ;;
 	esac
 	;;
-      netbsd*)
+      netbsd* | minix*)
 	;;
       *qnx* | *nto*)
         # QNX uses GNU C++, but need to define -shared option too, otherwise
@@ -4561,11 +4618,18 @@ m4_if([$1], [CXX], [
       ;;
 
     darwin* | rhapsody*)
-      # PIC is the default on this platform
+      # PIC is the default on this platform, and static linking of
+      # binaries generally doesn't work
       # Common symbols not allowed in MH_DYLIB files
       _LT_TAGVAR(lt_prog_compiler_pic, $1)='-fno-common'
+      _LT_TAGVAR(lt_prog_compiler_static, $1)=''
       ;;
 
+    *mint*)
+      # FreeMiNT does not support shared libraries at all
+      _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+      ;;
+
     haiku*)
       # PIC is the default for Haiku.
       # The "-static" flag exists, but is broken.
@@ -4591,6 +4655,13 @@ m4_if([$1], [CXX], [
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
@@ -4769,6 +4840,15 @@ m4_if([$1], [CXX], [
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
@@ -4844,6 +4924,9 @@ m4_if([$1], [CXX], [
 ])
 case $host_os in
   # For platforms that do not support PIC, -DPIC is meaningless:
+  mint*)
+    _LT_TAGVAR(lt_prog_compiler_pic, $1)=
+    ;;
   *djgpp*)
     _LT_TAGVAR(lt_prog_compiler_pic, $1)=
     ;;
@@ -5252,16 +5335,29 @@ _LT_EOF
       fi
       ;;
 
-    netbsd*)
-      if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
-	_LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
-	wlarc=
+    mirbsd*)
+      if test -f /usr/libexec/ld.so; then
+        _LT_TAGVAR(hardcode_direct, $1)=yes
+        _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+        _LT_TAGVAR(hardcode_direct_absolute, $1)=yes
+        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags'
+        _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag -o $lib $libobjs $deplibs $compiler_flags ${wl}-retain-symbols-file,$export_symbols'
+        _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+        _LT_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
       else
-	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags $wl-soname $wl$soname -o $lib'
-	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags $wl-soname $wl$soname $wl-retain-symbols-file $wl$export_symbols -o $lib'
+        _LT_TAGVAR(ld_shlibs, $1)=no
       fi
       ;;
 
+    netbsd* | minix*)
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
@@ -5794,15 +5890,28 @@ _LT_EOF
       esac
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
+    netbsd* | minix*)
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
       _LT_TAGVAR(hardcode_direct, $1)=yes
       _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+      output_verbose_link_cmd=func_echo_all
       ;;
 
     newsos6)
@@ -5814,6 +5923,11 @@ _LT_EOF
       ;;
 
     *nto* | *qnx*)
+      _LT_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+      _LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+      _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
+      _LT_TAGVAR(hardcode_direct, $1)=yes
+      _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
     openbsd* | bitrig*)
@@ -6287,9 +6401,7 @@ m4_defun([_LT_LANG_CXX_CONFIG],
 [m4_require([_LT_FILEUTILS_DEFAULTS])dnl
 m4_require([_LT_DECL_EGREP])dnl
 m4_require([_LT_PATH_MANIFEST_TOOL])dnl
-if test -n "$CXX" && ( test no != "$CXX" &&
-    ( (test g++ = "$CXX" && `g++ -v >/dev/null 2>&1` ) ||
-    (test g++ != "$CXX"))); then
+if test -n "$CXX" && test "X$CXX" != "Xno" ; then
   AC_PROG_CXXCPP
 else
   _lt_caught_CXX_error=yes
@@ -7079,6 +7191,22 @@ if test yes != "$_lt_caught_CXX_error"; then
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
@@ -7092,16 +7220,14 @@ if test yes != "$_lt_caught_CXX_error"; then
 	esac
 	;;
 
-      netbsd*)
-        if echo __ELF__ | $CC -E - | $GREP __ELF__ >/dev/null; then
-	  _LT_TAGVAR(archive_cmds, $1)='$LD -Bshareable  -o $lib $predep_objects $libobjs $deplibs $postdep_objects $linker_flags'
-	  wlarc=
-	  _LT_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
-	  _LT_TAGVAR(hardcode_direct, $1)=yes
-	  _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
-	fi
-	# Workaround some broken pre-1.5 toolchains
-	output_verbose_link_cmd='$CC -shared $CFLAGS -v conftest.$objext 2>&1 | $GREP conftest.$objext | $SED -e "s:-lgcc -lc -lgcc::"'
+      netbsd* | minix*)
+	_LT_TAGVAR(ld_shlibs, $1)=yes
+	_LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname -o $lib'
+	_LT_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $pic_flag $libobjs $deplibs $compiler_flags ${wl}-soname $wl$soname ${wl}-retain-symbols-file $wl$export_symbols -o $lib'
+	_LT_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-rpath,$libdir'
+	_LT_TAGVAR(hardcode_direct, $1)=yes
+	_LT_TAGVAR(hardcode_shlibpath_var, $1)=no
+	output_verbose_link_cmd=func_echo_all
 	;;
 
       *nto* | *qnx*)
@@ -7275,7 +7401,7 @@ if test yes != "$_lt_caught_CXX_error"; then
 	    # GNU C++ compiler with Solaris linker
 	    if test yes,no = "$GXX,$with_gnu_ld"; then
 	      _LT_TAGVAR(no_undefined_flag, $1)=' $wl-z ${wl}defs'
-	      if $CC --version | $GREP -v '^2\.7' > /dev/null; then
+	      if true; then
 	        _LT_TAGVAR(archive_cmds, $1)='$CC -shared $pic_flag -nostdlib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags $wl-h $wl$soname -o $lib'
 	        _LT_TAGVAR(archive_expsym_cmds, $1)='echo "{ global:" > $lib.exp~cat $export_symbols | $SED -e "s/\(.*\)/\1;/" >> $lib.exp~echo "local: *; };" >> $lib.exp~
                   $CC -shared $pic_flag -nostdlib $wl-M $wl$lib.exp $wl-h $wl$soname -o $lib $predep_objects $libobjs $deplibs $postdep_objects $compiler_flags~$RM $lib.exp'
@@ -7534,8 +7660,9 @@ if AC_TRY_EVAL(ac_compile); then
     -L* | -R* | -l*)
        # Some compilers place space between "-{L,R}" and the path.
        # Remove the space.
-       if test x-L = "$p" ||
-          test x-R = "$p"; then
+       if test x-L = x"$p" ||
+          test x-l = x"$p" ||
+          test x-R = x"$p"; then
 	 prev=$p
 	 continue
        fi
