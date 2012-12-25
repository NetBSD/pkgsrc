$NetBSD: patch-lib_hgfsServer_hgfsServer.c,v 1.1 2012/12/25 21:02:15 joerg Exp $

--- lib/hgfsServer/hgfsServer.c.orig	2012-12-25 19:41:00.000000000 +0000
+++ lib/hgfsServer/hgfsServer.c
@@ -2441,7 +2441,7 @@ HgfsServerStatFs(const char *pathName, /
     * delimiter on copy. Allow 0 length drives so that hidden feature "" can
     * work.
     */
-   if (pathLength < 0 || pathLength >= sizeof p.mountPoint) {
+   if (pathLength >= sizeof p.mountPoint) {
       LOG(4, ("HgfsServerStatFs: could not get the volume name\n"));
       return FALSE;
    }
@@ -3305,10 +3305,6 @@ HgfsCreateAndCacheFileNode(HgfsFileOpenI
     * for the share name, should be none.
     */
    len = CPName_GetComponentGeneric(openInfo->cpName, inEnd, "", &next);
-   if (len < 0) {
-      LOG(4, ("HgfsServerGetAccess: get first component failed\n"));
-      return FALSE;
-   }
 
    /* See if we are dealing with the base of the namespace */
    if (!len) {
