$NetBSD: patch-arjdata.c,v 1.1 2015/04/12 15:45:00 tnn Exp $

Add DragonFly support.

--- arjdata.c.orig	2004-04-17 11:44:46.000000000 +0000
+++ arjdata.c
@@ -64,6 +64,8 @@ static char *resources[][2]=
   #elif TARGET==UNIX
    #if defined(linux)
     "Linux"
+   #elif defined(__DragonFly__)
+    "DragonFly"
    #elif defined(__FreeBSD__)
     "FreeBSD"
    #elif defined(SUNOS)
@@ -91,6 +93,8 @@ static char *resources[][2]=
   "PLATFORM_APPENDIX",
   #if defined(linux)
    "/Linux",
+  #elif defined(__DragonFly__)
+   "/DragonFly", 
   #elif defined(__FreeBSD__)
    "/FreeBSD",
   #elif defined(SUNOS)
