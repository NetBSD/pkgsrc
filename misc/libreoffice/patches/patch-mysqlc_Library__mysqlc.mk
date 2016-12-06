$NetBSD: patch-mysqlc_Library__mysqlc.mk,v 1.1 2016/12/06 15:21:00 ryoon Exp $

--- mysqlc/Library_mysqlc.mk.orig	2016-07-28 22:11:19.000000000 +0000
+++ mysqlc/Library_mysqlc.mk
@@ -16,7 +16,7 @@ $(eval $(call gb_Library_use_externals,m
 
 ifeq ($(SYSTEM_MYSQL_CPPCONN),)
 $(eval $(call gb_Library_add_libs,mysqlc,\
-	$(if $(filter-out WNT,$(OS)),$(if $(filter MACOSX SOLARIS,$(OS)),-lz -lm,\
+	$(if $(filter-out WNT,$(OS)),$(if $(filter NETBSD MACOSX SOLARIS,$(OS)),-lz -lm,\
 	-rdynamic -lz -lcrypt -lnsl -lm)) \
 ))
 endif
