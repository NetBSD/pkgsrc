$NetBSD: manual-libtool.m4,v 1.5 2004/10/03 00:13:31 tv Exp $

--- libtool.m4.orig	2004-09-19 08:15:08.000000000 -0400
+++ libtool.m4
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
@@ -1400,15 +1402,22 @@ hpux9* | hpux10* | hpux11*)
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
@@ -1485,11 +1494,11 @@ knetbsd*-gnu)
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
@@ -1520,10 +1529,10 @@ nto-qnx*)
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
@@ -2198,6 +2207,10 @@ hpux10.20* | hpux11*)
   esac
   ;;
 
+interix3*)
+  lt_cv_deplibs_check_method='match_pattern /lib[[^/]]+(\.so|_pic\.a)$'
+  ;;
+
 irix5* | irix6* | nonstopux*)
   case $LD in
   *-32|*"-32 ") libmagic=32-bit;;
@@ -3091,6 +3104,8 @@ case $host_os in
 	;;
     esac
     ;;
+  interix3*)
+    ;;
   irix5* | irix6*)
     case $cc_basename in
       CC)
@@ -3210,6 +3225,13 @@ case $host_os in
     if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
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
@@ -3651,6 +3673,14 @@ if AC_TRY_EVAL(ac_compile); then
     esac
   done
 
+  case "$host_os" in
+  netbsd*)
+    if test -n "$cpprt0_file"; then
+      predep_objects_CXX=`eval echo $predep_objects_CXX | sed -e 's:/usr/lib/c++rt0.o:$cpprt0_file:'`
+    fi
+    ;;
+  esac
+
   # Clean up.
   rm -f a.out a.exe
 else
@@ -4591,9 +4621,11 @@ AC_MSG_CHECKING([for $compiler option to
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
@@ -4615,6 +4647,10 @@ AC_MSG_CHECKING([for $compiler option to
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
@@ -4689,6 +4725,8 @@ AC_MSG_CHECKING([for $compiler option to
 	    ;;
 	esac
 	;;
+      interix3*)
+	;;
       irix5* | irix6* | nonstopux*)
 	case $cc_basename in
 	  CC)
@@ -4854,9 +4892,11 @@ AC_MSG_CHECKING([for $compiler option to
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
@@ -4885,6 +4925,11 @@ AC_MSG_CHECKING([for $compiler option to
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
@@ -5187,6 +5232,17 @@ EOF
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
+      _LT_AC_TAGVAR(archive_expsym_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-h,$soname ${wl}--retain-symbols-file $wl$export_symbols ${wl}--image-base,$(($RANDOM %4096/2*262144+1342177280)) -o $lib'
+      ;;
+
     netbsd*)
       if echo __ELF__ | $CC -E - | grep __ELF__ >/dev/null; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable $libobjs $deplibs $linker_flags -o $lib'
@@ -5592,6 +5648,20 @@ $echo "local: *; };" >> $output_objdir/$
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
+      _LT_AC_TAGVAR(export_dynamic_flag_spec, $1)='${wl}-E'
+      _LT_AC_TAGVAR(hardcode_direct, $1)=yes
+      _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='${wl}-h,$libdir'
+      _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
+      ;;
+
     irix5* | irix6* | nonstopux*)
       if test "$GCC" = yes; then
 	_LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared $libobjs $deplibs $compiler_flags ${wl}-soname ${wl}$soname `test -n "$verstring" && echo ${wl}-set_version ${wl}$verstring` ${wl}-update_registry ${wl}${output_objdir}/so_locations -o $lib'
