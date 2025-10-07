$NetBSD: patch-core_src_os_unix_gnatcoll-os-libc.ads,v 1.1 2025/10/07 20:45:11 dkazankov Exp $

Use separate package for constants definition

--- core/src/os/unix/gnatcoll-os-libc.ads.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/unix/gnatcoll-os-libc.ads
@@ -157,19 +157,17 @@
    --  See POSIX posix_fadvise function. Note that on some platforms such as
    --  MacOS, the function does nothing as the underlying system call does not
    --  exist.
-   type Posix_Fadvise_Code is
-      (POSIX_FADV_NORMAL,
-       POSIX_FADV_SEQUENTIAL,
-       POSIX_FADV_RANDOM,
-       POSIX_FADV_NOREUSE,
-       POSIX_FADV_WILLNEED);
-   for Posix_Fadvise_Code'Size use Integer'Size;
-   for Posix_Fadvise_Code use
-      (POSIX_FADV_NORMAL     => 0,
-       POSIX_FADV_SEQUENTIAL => 1,
-       POSIX_FADV_RANDOM     => 2,
-       POSIX_FADV_NOREUSE    => 3,
-       POSIX_FADV_WILLNEED   => 4);
+   type Posix_Fadvise_Code is new Integer;
+   POSIX_FADV_NORMAL : constant Posix_Fadvise_Code :=
+      Constants.POSIX_FADV_NORMAL;
+   POSIX_FADV_SEQUENTIAL : constant Posix_Fadvise_Code :=
+      Constants.POSIX_FADV_SEQUENTIAL;
+   POSIX_FADV_RANDOM : constant Posix_Fadvise_Code :=
+      Constants.POSIX_FADV_RANDOM;
+   POSIX_FADV_NOREUSE : constant Posix_Fadvise_Code :=
+      Constants.POSIX_FADV_NOREUSE;
+   POSIX_FADV_WILLNEED : constant Posix_Fadvise_Code :=
+      Constants.POSIX_FADV_WILLNEED;
 
    function Posix_Fadvise
       (FD     : FS.File_Descriptor;
@@ -246,11 +244,11 @@
         Convention    => C,
         External_Name => "waitpid";
 
-   EPERM : constant Integer := 1;
+   EPERM : constant Integer := Constants.EPERM;
    --  EPERM is set to 1 on all supported system
 
-   EINVAL : constant Integer := 22;
-   ENOSYS : constant Integer := 38;
+   EINVAL : constant Integer := Constants.EINVAL;
+   ENOSYS : constant Integer := Constants.ENOSYS;
 
    function Errno return Integer
    with Import        => True,
