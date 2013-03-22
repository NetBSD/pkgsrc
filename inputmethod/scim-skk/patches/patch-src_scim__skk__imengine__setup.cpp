$NetBSD: patch-src_scim__skk__imengine__setup.cpp,v 1.1 2013/03/22 13:37:21 obache Exp $

* require include <cstring> for strcmp().

--- src/scim_skk_imengine_setup.cpp.orig	2005-12-18 12:15:53.000000000 +0000
+++ src/scim_skk_imengine_setup.cpp
@@ -32,6 +32,7 @@
 #endif
 
 #include <vector>
+#include <cstring>
 
 #include <scim.h>
 #include <gtk/scimkeyselection.h>
