$NetBSD: patch-autoopts_mk-tpl-config.sh,v 1.1 2016/07/16 20:00:14 wiz Exp $

Allow passing in perl path, to avoid reference to tools/ dir.

--- autoopts/mk-tpl-config.sh.orig	2015-08-08 23:12:01.000000000 +0000
+++ autoopts/mk-tpl-config.sh
@@ -98,7 +98,7 @@ fix_scripts() {
         st=`sed 1q $f`
 
         case "$st" in
-        *perl ) echo '#!' `which perl`
+        *perl ) echo '#!' ${PERL5}
                  sed 1d $f
                  ;;
 
