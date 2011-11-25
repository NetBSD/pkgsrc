$NetBSD: patch-common_Persistent.h,v 1.1 2011/11/25 21:42:44 joerg Exp $

--- common/Persistent.h.orig	2011-11-25 17:55:49.000000000 +0000
+++ common/Persistent.h
@@ -47,9 +47,9 @@ public:
 	CPersistent(const char *uniqueName, kClassPersistent pclass);
 	virtual ~CPersistent();
 
-	virtual unsigned int SizeOf(void) const = 0L;
-	virtual const void *GetData(void) const = 0L;
-	virtual void SetData(const void *ptr, unsigned int size) = 0L;
+	virtual unsigned int SizeOf(void) const = 0;
+	virtual const void *GetData(void) const = 0;
+	virtual void SetData(const void *ptr, unsigned int size) = 0;
 		// virtual access
 	
 	static void SaveAll(void);
