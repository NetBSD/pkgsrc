$NetBSD: patch-makedep.sh,v 1.1 2012/10/18 16:58:18 asau Exp $

"echo -e" is not portable.

--- makedep.sh.orig	2007-09-21 08:48:19.000000000 +0000
+++ makedep.sh
@@ -3,17 +3,21 @@
 # Script for automatic generation of Makefile dependencies
 # Receives list of .c files as arguments
 
-echo "# Created by makedep.sh, do not edit" > Makefile.dep
-echo "" >> Makefile.dep
+exec > Makefile.dep
+
+echo "# Created by makedep.sh, do not edit"
+echo
 
 for x in $@
 do
-  if ! $CPP $CPPFLAGS -E -MG -MM $x >> Makefile.dep ; then
+  if ! $CPP $CPPFLAGS -E -MG -MM $x ; then
     rm -f Makefile.dep
     exit 1
   fi
-  echo -e "\t\$(MPICC) -c \$(CFLAGS) $x" >> Makefile.dep
+  printf "\t"
+  echo "\$(MPICC) -c \$(CFLAGS) $x"
 done
 
-echo "skampi: $OBJECTS"   >> Makefile.dep
-echo -e "\t\$(MPICC) -o skampi $OBJECTS -lm" >> Makefile.dep
+echo "skampi: $OBJECTS"
+printf "\t"
+echo -e "\$(MPICC) -o skampi $OBJECTS -lm"
