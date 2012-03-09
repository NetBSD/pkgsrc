$NetBSD: patch-sql_ha_ndbcluster.cc,v 1.1 2012/03/09 12:38:27 fhajny Exp $

Fix for ar/ld toolchain on SunOS, see:
http://bugs.mysql.com/bug.php?id=34866
--- sql/ha_ndbcluster.cc.orig	2011-10-29 18:09:49.000000000 +0000
+++ sql/ha_ndbcluster.cc
@@ -10549,5 +10549,6 @@ mysql_declare_plugin(ndbcluster)
   NULL                        /* config options                  */
 }
 mysql_declare_plugin_end;
-
+#else
+int Sun_linker_needs_a_symbol_here= 0;
 #endif
