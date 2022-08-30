$NetBSD: patch-makefilegen.sh,v 1.1 2022/08/30 17:55:31 schmonz Exp $

Apply upstream commit 0cb7bb4 to fall back to /dev/urandom on systems
where getentropy() is not present.

--- makefilegen.sh.orig	2022-08-14 12:18:16.000000000 +0000
+++ makefilegen.sh
@@ -9,6 +9,7 @@
     echo "DESTDIR?="
     echo 
 
+    # binaries
     i=0
     for file in `ls *.c`; do
       if grep '^int main(' "${file}" >/dev/null; then
@@ -23,18 +24,40 @@
     done
     echo
 
+    # portable
+    headers=`ls *.c-* | sed 's/\.c-.*/.h/' | sort -u`
+
     echo "all: bearssl \$(BINARIES) tlswrapper-tcp tlswrapper-smtp"
     echo 
 
+    for hfile in "${headers}"; do
+      echo "${hfile}:"
+      ls "${hfile}-"* \
+      | sort \
+      | while read hhfile
+      do
+        ccfile=`echo ${hhfile} | sed 's/\.h-/.c-/'`
+        echo "	(grep -v \"${hfile}\" \"${ccfile}\"; echo \"int main() {}\";) > try.c"
+        echo "	[ ! -f ${hfile} ] && \$(CC) \$(CFLAGS) \$(CPPFLAGS) \$(LDFLAGS) -o try try.c && cat ${hhfile} > ${hfile} || :"
+      done
+      echo "	rm try.c try"
+      touch "${hfile}"
+    done
+    echo
+
+
     for file in `ls *.c`; do
       (
-        #gcc -I/usr/include/bearssl -MM "${file}"
         gcc -MM "${file}"
         echo "	\$(CC) \$(CFLAGS) \$(CPPFLAGS) -c ${file}"
         echo
       )
     done
 
+    for hfile in "${headers}"; do
+      rm -f "${hfile}"
+    done
+
     i=0
     for file in `ls *.c`; do
       if ! grep '^int main(' "${file}" >/dev/null; then
@@ -61,8 +84,8 @@
 
     echo "bearssl:"
     echo "	echo 'int main(){}' > try.c"
-    echo "	\$(CC) \$(CFLAGS) \$(CPPFLAGS) -o try.o \$(LDFLAGS) try.c || (sh bearssl.sh; cd bearssl; make; rm build/*.so; )"
-    echo "	rm -f try.o try.c"
+    echo "	\$(CC) \$(CFLAGS) \$(CPPFLAGS) \$(LDFLAGS) -o try try.c || (sh bearssl.sh; cd bearssl; make; rm build/*.so; )"
+    echo "	rm -f try.c try"
     echo "	mkdir -p bearssl/inc"
     echo
 
@@ -94,6 +117,9 @@
 
     echo "clean:"
     echo "	rm -f *.o *.out \$(BINARIES) tlswrapper-tcp tlswrapper-smtp"
+    for hfile in "${headers}"; do
+      echo "	rm -f ${hfile}"
+    done
     echo 
 
   ) > Makefile
