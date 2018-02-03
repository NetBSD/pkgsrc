$NetBSD: patch-mysqlc_Library__mysqlc.mk,v 1.2 2018/02/03 00:39:50 ryoon Exp $

--- mysqlc/Library_mysqlc.mk.orig	2018-01-24 20:31:03.000000000 +0000
+++ mysqlc/Library_mysqlc.mk
@@ -16,7 +16,7 @@ $(eval $(call gb_Library_use_externals,m
 
 ifeq ($(SYSTEM_MYSQL_CONNECTOR_CPP),)
 $(eval $(call gb_Library_add_libs,mysqlc,\
-	$(if $(filter-out WNT,$(OS)),$(if $(filter MACOSX SOLARIS,$(OS)),-lz -lm,\
+	$(if $(filter-out WNT,$(OS)),$(if $(filter NETBSD MACOSX SOLARIS,$(OS)),-lz -lm,\
 	-rdynamic -lz -lcrypt -lnsl -lm)) \
 ))
 endif
