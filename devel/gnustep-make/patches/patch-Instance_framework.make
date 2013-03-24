$NetBSD: patch-Instance_framework.make,v 1.1 2013/03/24 17:02:37 joerg Exp $

--- Instance/framework.make.orig	2013-03-23 21:46:20.000000000 +0000
+++ Instance/framework.make
@@ -484,7 +484,7 @@ $(DUMMY_FRAMEWORK_FILE): $(DERIVED_SOURC
 	fi; \
 	echo "$$classarray" > $(DUMMY_FRAMEWORK_CLASS_LIST); \
 	echo "#include <Foundation/NSString.h>" > $@; \
-	echo "@interface $(DUMMY_FRAMEWORK)" >> $@; \
+	echo "@interface $(DUMMY_FRAMEWORK) : NSObject" >> $@; \
 	echo "+ (NSString *)frameworkEnv;" >> $@; \
 	echo "+ (NSString *)frameworkPath;" >> $@; \
 	echo "+ (NSString *)frameworkVersion;" >> $@; \
