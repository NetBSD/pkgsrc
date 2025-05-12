$NetBSD: patch-screen.c,v 1.2 2025/05/12 15:58:01 wiz Exp $

Use standard headers.

Also:
https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- screen.c.orig	2023-08-16 00:29:26.000000000 +0000
+++ screen.c
@@ -95,6 +95,8 @@
 # include <langinfo.h>
 #endif
 
+#include <limits.h>
+
 #include "screen.h"
 #ifdef HAVE_BRAILLE
 # include "braille.h"
@@ -230,8 +232,6 @@ char *multi_home;
 int multi_uid;
 int own_uid;
 int multiattach;
-int tty_mode;
-int tty_oldmode = -1;
 #endif
 
 char HostName[MAXSTR];
@@ -1009,9 +1009,6 @@ int main(int ac, char** av)
 
     /* ttyname implies isatty */
     SetTtyname(true, &st);
-#ifdef MULTIUSER
-    tty_mode = (int)st.st_mode & 0777;
-#endif
 
     fl = fcntl(0, F_GETFL, 0);
     if (fl != -1 && (fl & (O_RDWR|O_RDONLY|O_WRONLY)) == O_RDWR)
@@ -1127,15 +1124,28 @@ int main(int ac, char** av)
 #endif
   }
 
-  if (stat(SockPath, &st) == -1)
-    Panic(errno, "Cannot access %s", SockPath);
-  else
-    if (!S_ISDIR(st.st_mode))
+  if (stat(SockPath, &st) == -1) {
+    if (eff_uid == real_uid) {
+      Panic(errno, "Cannot access %s", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  } else if (!S_ISDIR(st.st_mode)) {
+    if (eff_uid == real_uid || st.st_uid == real_uid) {
       Panic(0, "%s is not a directory.", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  }
 #ifdef MULTIUSER
   if (multi) {
-    if ((int)st.st_uid != multi_uid)
-      Panic(0, "%s is not the owner of %s.", multi, SockPath);
+    if ((int)st.st_uid != multi_uid) {
+      if (eff_uid == real_uid || st.st_uid == real_uid) {
+        Panic(0, "%s is not the owner of %s.", multi, SockPath);
+      } else {
+        Panic(0, "Error accessing %s", SockPath);
+      }
+    }
   }
   else
 #endif
@@ -1150,8 +1160,13 @@ int main(int ac, char** av)
 #endif
   }
 
-  if ((st.st_mode & 0777) != 0700)
-    Panic(0, "Directory %s must have mode 700.", SockPath);
+  if ((st.st_mode & 0777) != 0700) {
+    if (eff_uid == real_uid || st.st_uid == real_uid) {
+      Panic(0, "Directory %s must have mode 700.", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  }
   if (SockMatch && index(SockMatch, '/'))
     Panic(0, "Bad session name '%s'", SockMatch);
   SockName = SockPath + strlen(SockPath) + 1;
@@ -1189,8 +1204,13 @@ int main(int ac, char** av)
       else
         exit(9 + (fo || oth ? 1 : 0) + fo);
     }
-    if (fo == 0)
-      Panic(0, "No Sockets found in %s.\n", SockPath);
+    if (fo == 0) {
+      if (eff_uid == real_uid || st.st_uid == real_uid) {
+        Panic(0, "No Sockets found in %s.\n", SockPath);
+      } else {
+        Panic(0, "Error accessing %s", SockPath);
+      }
+    }
     Msg(0, "%d Socket%s in %s.", fo, fo > 1 ? "s" : "", SockPath);
     eexit(0);
   }
@@ -2170,20 +2190,6 @@ DEFINE_VARARGS_FN(Panic)
       if (D_userpid)
         Kill(D_userpid, SIG_BYE);
     }
-#ifdef MULTIUSER
-  if (tty_oldmode >= 0) {
-
-# ifdef USE_SETEUID
-    if (setuid(own_uid))
-      xseteuid(own_uid);	/* may be a loop. sigh. */
-# else
-      setuid(own_uid);
-# endif
-
-    debug1("Panic: changing back modes from %s\n", attach_tty);
-    chmod(attach_tty, tty_oldmode);
-  }
-#endif
   eexit(1);
 }
 
