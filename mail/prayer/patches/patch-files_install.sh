$NetBSD: patch-files_install.sh,v 1.1 2011/06/30 01:17:38 schnoebe Exp $

--- files/install.sh.orig	2008-09-16 09:59:56.000000000 +0000
+++ files/install.sh
@@ -67,14 +67,18 @@ if [ ! -d ${PREFIX}/etc ]; then
     ${INSTALL} -d -o ${RO_USER} -g ${RO_GROUP} -m ${PUBLIC_DIR} ${PREFIX}/etc
 fi
 
-if [ ! -d ${PREFIX}/certs ]; then
-    ${INSTALL} -d -o ${RO_USER} -g ${RO_GROUP} -m ${PRIVATE_DIR} ${PREFIX}/certs
+if [ ! -d ${SSLCERTS} ]; then
+    ${BSD_INSTALL_DATA_DIR} ${SSLCERTS}
 fi
 
 if [ ! -d ${BIN_DIR} ]; then
     ${INSTALL} -d -o ${RO_USER} -g ${RO_GROUP} -m ${PUBLIC_DIR} ${BIN_DIR}
 fi
 
+if [ ! -d "${PREFIX}/share/prayer" ]; then
+	mkdir "${PREFIX}/share/prayer"
+fi
+
 for i in icons static
 do
     if [ -d "${PREFIX}/${i}" ]; then
@@ -82,6 +86,6 @@ do
         rm -rf ${PREFIX}/${i}
     fi
     echo Copying ${i}
-    (tar cf - ${i}) | (cd ${PREFIX} ; tar xf -)
-    (cd ${PREFIX}; chown -R ${RO_USER}:${RO_GROUP} ${i})
+    (tar cf - ${i}) | (cd ${PREFIX}/share/prayer ; tar xf -)
+    # (cd ${PREFIX}; chown -R ${RO_USER}:${RO_GROUP} ${i})
 done
