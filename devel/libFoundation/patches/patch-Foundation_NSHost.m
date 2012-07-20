$NetBSD: patch-Foundation_NSHost.m,v 1.1 2012/07/20 23:46:44 marino Exp $

Add macros for DragonFly version of gethostbyname_r and gethostbyaddr_r
XXX int	gethostbyaddr_r(const void *, socklen_t, int, struct hostent *,
			char *, size_t, struct hostent **, int *);
XXX int	gethostbyname_r(const char *, struct hostent *, char *, size_t,
			struct hostent **, int *);

--- Foundation/NSHost.m.orig	2008-11-02 16:00:07.000000000 +0000
+++ Foundation/NSHost.m
@@ -205,6 +205,9 @@ static NSRecursiveLock     *hostsLock =
     int            hErrno;
     // size as described in "UNIX Network Programming" by Richard Stevens
     char           buffer[8192]; 
+#if defined(__DragonFly__)
+    struct hostent *result;
+#endif 
 #else
     struct hostent *hostEntity;
 #endif
@@ -223,7 +226,12 @@ static NSRecursiveLock     *hostsLock =
 
 #if HAVE_GETHOSTBYNAME_R && !defined(linux)
     if (gethostbyname_r([name cString], &hostEntity,
-                        buffer, sizeof(buffer), &hErrno) == NULL) {
+                        buffer, sizeof(buffer),
+#if defined(__DragonFly__)
+                        &result, &hErrno) == 0) {
+#else
+                        &hErrno) == NULL) {
+#endif
         RELEASE(self);
         return nil;
     }
@@ -252,6 +260,9 @@ static NSRecursiveLock     *hostsLock =
     int            hErrno;
     // as described in "UNIX Network Programming" by Richard Stevens
     char           buffer[8192]; 
+#if defined(__DragonFly__)
+    struct hostent *result;
+#endif 
 #else
     struct hostent *hostEntity;
 #endif
@@ -277,7 +288,12 @@ static NSRecursiveLock     *hostsLock =
 
 #if HAVE_GETHOSTBYADDR_R && !defined(linux)
     if (gethostbyaddr_r((char*)&ipAddress, sizeof(ipAddress), AF_INET,
-                        &hostEntity, buffer, sizeof(buffer), &hErrno) == NULL) {
+                        &hostEntity, buffer, sizeof(buffer),
+#if defined(__DragonFly__)
+                        &result, &hErrno) == 0) {
+#else
+                        &hErrno) == NULL) {
+#endif
         RELEASE(self);
         return nil;
     }
