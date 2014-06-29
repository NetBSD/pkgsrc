$NetBSD: patch-exptild.c,v 1.1 2014/06/29 05:45:57 dholland Exp $

Avoid cuserid(). It doesn't exist everywhere and it's useless anyway.

--- exptild.c~	1995-05-07 19:34:19.000000000 +0000
+++ exptild.c
@@ -180,8 +180,6 @@ char
 
             username = (char *) getlogin();
             if (username == (char *) NULL)
-                username = cuserid ((char *) NULL);
-                    if (username == (char *) NULL)
                     {
                         setpwent();
                         if ((ptr = getpwuid ((uid_t) getuid())) 
