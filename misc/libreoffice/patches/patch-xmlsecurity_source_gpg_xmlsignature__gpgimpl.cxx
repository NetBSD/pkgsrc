$NetBSD: patch-xmlsecurity_source_gpg_xmlsignature__gpgimpl.cxx,v 1.1 2017/08/01 11:57:37 ryoon Exp $

* Do not confuse wth key.h from gpgmepp and nss

--- xmlsecurity/source/gpg/xmlsignature_gpgimpl.cxx.orig	2017-07-25 20:26:39.000000000 +0000
+++ xmlsecurity/source/gpg/xmlsignature_gpgimpl.cxx
@@ -23,7 +23,7 @@
 
 #include <gpgme.h>
 #include <context.h>
-#include <key.h>
+#include <gpgme++/key.h>
 #include <data.h>
 #include <signingresult.h>
 #include <importresult.h>
