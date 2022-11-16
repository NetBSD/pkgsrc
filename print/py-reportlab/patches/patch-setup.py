$NetBSD: patch-setup.py,v 1.1 2022/11/16 12:18:46 gdt Exp $

Add /usr/X11R7 to the set of places setup.py looks for.  The existing
setup.py is problematic, because this behavior escapes from buildlink,
and because it is not just trying a test compile with the provided
CPPFLAGS.  Given that there is already a list of questionable places
(/usr/local), it is not incrementally worse to add in X11R7.

Not yet sent upstream.

--- setup.py.orig	2022-10-17 12:06:28.000000000 +0000
+++ setup.py
@@ -277,6 +277,8 @@ class inc_lib_dirs:
             # darwin ports installation directories
             aDir(L, "/opt/local/lib")
             aDir(I, "/opt/local/include")
+        aDir(I, "/usr/X11R7/include")
+        aDir(L, "/usr/X11R7/lib")
         aDir(I, "/usr/local/include")
         aDir(L, "/usr/local/lib")
         aDir(I, "/usr/include")
