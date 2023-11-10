$NetBSD: patch-Modules_clinic_posixmodule.c.h,v 1.1 2023/11/10 09:48:40 nia Exp $

posix.copyfile does not exist on Tiger. 

Python 3.8's posix._fcopyfile implementation unconditionally uses <copyfile.h>, 
which only exists on Leopard ane newer. This patch removes posix._fcopyfile 
on Tiger - this is okay because the rest of the stdlib uses posix._fcopyfile 
only conditionally after checking that the function exists 
(non-Apple systems don't have posix._fcopyfile either).


thanks to @dgelessus
https://github.com/macports/macports-ports/pull/5987

--- Modules/clinic/posixmodule.c.h.orig	2023-08-24 12:46:25.000000000 +0000
+++ Modules/clinic/posixmodule.c.h
@@ -5270,7 +5270,7 @@ exit:
 
 #endif /* defined(HAVE_SENDFILE) && !defined(__APPLE__) && !(defined(__FreeBSD__) || defined(__DragonFly__)) */
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED >= 1050
 
 PyDoc_STRVAR(os__fcopyfile__doc__,
 "_fcopyfile($module, in_fd, out_fd, flags, /)\n"
