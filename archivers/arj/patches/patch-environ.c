$NetBSD: patch-environ.c,v 1.3 2025/04/21 16:15:46 wiz Exp $

Add support for various OSes.
Fix CVE-2015-0557. Via Debian security-traversal-dir.patch.

--- environ.c.orig	2015-04-12 15:49:08.000000000 +0000
+++ environ.c
@@ -58,10 +58,10 @@
   #include <sys/ioctl.h>
   #include <sys/statfs.h>
   #include <sys/statvfs.h>
- #elif defined(__FreeBSD__)||defined(__NetBSD__)
+ #elif defined(__FreeBSD__)||defined(__NetBSD__)||defined(__APPLE__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__OpenBSD__)
   #include <sys/param.h>
   #include <sys/mount.h>
  #elif defined(__QNXNTO__)
   #include <sys/statvfs.h>
  #else
   #include <sys/statfs.h>
@@ -1087,6 +1087,8 @@ static char *validate_path(char *name)
   if(action!=VALIDATE_DRIVESPEC)
   {
 #endif
+   while (name[0]!='\0'&&
+          (name[0]=='.'||name[0]==PATHSEP_DEFAULT||name[0]==PATHSEP_UNIX)) {
    if(name[0]=='.')
    {
     if(name[1]=='.'&&(name[2]==PATHSEP_DEFAULT||name[2]==PATHSEP_UNIX))
@@ -1096,6 +1098,7 @@ static char *validate_path(char *name)
    }
    if(name[0]==PATHSEP_DEFAULT||name[0]==PATHSEP_UNIX)
     name++;                             /* "\\" - revert to root */
+   }
 #if SFX_LEVEL>=ARJSFXV
   }
  }
@@ -2286,7 +2289,7 @@ unsigned long file_getfree(char *name)
   else
    return((LONG_MAX/(spclu*bps)<fclu)?LONG_MAX:spclu*bps*fclu);
  #elif TARGET==UNIX
-  #if defined(__QNXNTO__)||defined(__sco__)||defined(SUNOS)
+  #if defined(__QNXNTO__)||defined(__sco__)||defined(SUNOS)||(defined(__NetBSD__) && (__NetBSD_Version__ >= 299000900))
    struct statvfs vfs;
 
    if(statvfs(name, &vfs)==-1)
@@ -3005,7 +3008,7 @@ void get_exe_name(char *dest, char *arg)
     they are missing altogether, the corresponding code will gracefully
     terminate. */
  #if SFX_LEVEL==ARJ
-  strcpy(dest, "/usr/local/bin/arj");
+  strcpy(dest, "@PREFIX@/bin/arj");
  #elif SFX_LEVEL==ARJSFXV
   strcpy(dest, "./arjsfxv");
  #elif SFX_LEVEL==ARJSFX
@@ -3013,7 +3016,7 @@ void get_exe_name(char *dest, char *arg)
  #elif SFX_LEVEL==ARJSFXJR
   strcpy(dest, "./arjsfxjr");
  #elif defined(REARJ)
-  strcpy(dest, "/usr/local/bin/rearj");
+  strcpy(dest, "@PREFIX@/bin/rearj");
  #else
   dest[0]='\0';
  #endif
