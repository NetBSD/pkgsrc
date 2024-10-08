$NetBSD: patch-external_libcmis_UnpackedTarball__libcmis.mk,v 1.1 2024/10/08 05:57:31 ryoon Exp $

--- external/libcmis/UnpackedTarball_libcmis.mk.orig	2024-09-04 06:27:55.382269717 +0000
+++ external/libcmis/UnpackedTarball_libcmis.mk
@@ -25,6 +25,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
 	external/libcmis/0001-cppcheck-operatorEqVarError-in-src-libcmis-http-sess.patch \
 	external/libcmis/0001-Take-into-account-m_CurlInitProtocolsFunction-in-cop.patch \
 	external/libcmis/initprotocols.patch.1 \
+	external/libcmis/boost186.patch.1 \
 ))
 
 # vim: set noet sw=4 ts=4:
