$NetBSD: patch-ld_genscripts.sh,v 1.1 2020/12/14 00:39:33 dbj Exp $

https://sourceware.org/bugzilla/show_bug.cgi?id=5652

--- ld/genscripts.sh.orig	2007-08-12 19:00:07.000000000 +0000
+++ ld/genscripts.sh
@@ -390,7 +390,15 @@ case " $EMULATION_LIBPATH " in
     *" ${EMULATION_NAME} "*) COMPILE_IN=true;;
 esac
 
-if test -n "${BASH+set}"; then
+# Determine if the shell has support for the variable BASH_LINENO.
+# When it is the case, it is only available inside functions.
+has_lineno()
+{
+  test "x$BASH_LINENO" != "x"
+}
+
+# Enable accruate error source in the compiler error messages, if possible.
+if has_lineno; then
   source_em()
   {
     local current_script="$em_script"
