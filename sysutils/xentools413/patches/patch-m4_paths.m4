$NetBSD: patch-m4_paths.m4,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- m4/paths.m4.orig
+++ m4/paths.m4
@@ -135,8 +135,9 @@ XEN_SCRIPT_DIR=$XEN_CONFIG_DIR/scripts
 AC_SUBST(XEN_SCRIPT_DIR)
 
 case "$host_os" in
-*freebsd*) XEN_LOCK_DIR=$localstatedir/lib ;;
-*netbsd*) XEN_LOCK_DIR=$localstatedir/lib ;;
+*freebsd*) XEN_LOCK_DIR=$rundir_path ;;
+*netbsd*) XEN_LOCK_DIR=$rundir_path ;;
+*openbsd*) XEN_LOCK_DIR=$rundir_path ;;
 *) XEN_LOCK_DIR=$localstatedir/lock ;;
 esac
 AC_SUBST(XEN_LOCK_DIR)
