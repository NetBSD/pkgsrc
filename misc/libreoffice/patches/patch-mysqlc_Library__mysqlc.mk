$NetBSD: patch-mysqlc_Library__mysqlc.mk,v 1.3 2018/08/18 00:11:32 ryoon Exp $

--- mysqlc/Library_mysqlc.mk.orig	2018-08-02 19:54:54.000000000 +0000
+++ mysqlc/Library_mysqlc.mk
@@ -16,7 +16,7 @@ $(eval $(call gb_Library_use_externals,m
 
 ifeq ($(SYSTEM_MYSQL_CONNECTOR_CPP),)
 $(eval $(call gb_Library_add_libs,mysqlc,\
-	$(if $(filter-out WNT,$(OS)),$(if $(filter MACOSX SOLARIS,$(OS)),-lz -lm,\
+	$(if $(filter-out WNT,$(OS)),$(if $(filter NETBSD MACOSX SOLARIS,$(OS)),-lz -lm,\
 	-rdynamic -lz -lcrypt -lm)) \
 ))
 endif
