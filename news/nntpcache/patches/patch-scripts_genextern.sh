$NetBSD: patch-scripts_genextern.sh,v 1.1 2017/12/27 16:53:43 he Exp $

Don't create syntax error.

--- scripts/genextern.sh.orig	2004-04-11 11:43:50.000000000 +0000
+++ scripts/genextern.sh
@@ -8,6 +8,7 @@ shift
 $CPP -DAUTOGEN -DEXPORT=GENEXTERN $* $input | egrep 'GENEXTERN  *') |\
 sed -e '{
 s/GENEXTERN /extern /
+s/($/()/
 s/=.*$//
 s/;.*$//
 s/$/;/
@@ -43,4 +44,4 @@ END
 }
 #endif
 END2
-)
\ No newline at end of file
+)
