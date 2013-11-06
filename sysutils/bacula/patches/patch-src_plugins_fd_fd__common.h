$NetBSD: patch-src_plugins_fd_fd__common.h,v 1.1 2013/11/06 16:00:05 joerg Exp $

Replacements for new and delete must be global according to ISO C++.
This file is only used by a test case, so just drop them.

--- src/plugins/fd/fd_common.h.orig	2013-11-06 15:38:19.000000000 +0000
+++ src/plugins/fd/fd_common.h
@@ -71,46 +71,6 @@ DLL_IMP_EXP void reallyfree(const char *
 #define malloc(s)    sm_malloc(__FILE__, __LINE__, (s))
 #define free(o)      sm_free(__FILE__, __LINE__, (o))
 
-inline void *operator new(size_t size, char const * file, int line)
-{
-   void *pnew = sm_malloc(file,line, size);
-   memset((char *)pnew, 0, size);
-   return pnew;
-}
-
-inline void *operator new[](size_t size, char const * file, int line)
-{
-   void *pnew = sm_malloc(file, line, size);
-   memset((char *)pnew, 0, size);
-   return pnew;
-}
-
-inline void *operator new(size_t size)
-{
-   void *pnew = sm_malloc(__FILE__, __LINE__, size);
-   memset((char *)pnew, 0, size);
-   return pnew;
-}
-
-inline void *operator new[](size_t size)
-{
-   void *pnew = sm_malloc(__FILE__, __LINE__, size);
-   memset((char *)pnew, 0, size);
-   return pnew;
-}
-
-#define new   new(__FILE__, __LINE__)
-
-inline void operator delete(void *buf)
-{
-   sm_free( __FILE__, __LINE__, buf);
-}
-
-inline void operator delete[] (void *buf)
-{
-  sm_free(__FILE__, __LINE__, buf);
-}
-
 #define Dmsg(context, level,  ...) bfuncs->DebugMessage(context, __FILE__, __LINE__, level, __VA_ARGS__ )
 #define Jmsg(context, type,  ...) bfuncs->JobMessage(context, __FILE__, __LINE__, type, 0, __VA_ARGS__ )
 
