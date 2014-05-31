$NetBSD: patch-libgo_config_libtool.m4,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- libgo/config/libtool.m4.orig	2014-04-04 13:53:39.000000000 +0000
+++ libgo/config/libtool.m4
@@ -2552,7 +2552,7 @@ openbsd*)
     *)				need_version=no  ;;
   esac
   library_names_spec='${libname}${release}${shared_ext}$versuffix ${libname}${shared_ext}$versuffix'
-  finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
+  #finish_cmds='PATH="\$PATH:/sbin" ldconfig -m $libdir'
   shlibpath_var=LD_LIBRARY_PATH
   if test -z "`echo __ELF__ | $CC -E - | $GREP __ELF__`" || test "$host_os-$host_cpu" = "openbsd2.8-powerpc"; then
     case $host_os in
