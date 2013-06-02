$NetBSD: patch-jdk_src_solaris_classes_sun_nio_fs_BsdFileSystemProvider.java,v 1.1 2013/06/02 06:12:28 ryoon Exp $

* From rhino.patch.

--- jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java.orig	2012-08-10 17:31:24.000000000 +0000
+++ jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
@@ -27,6 +27,7 @@ package sun.nio.fs;
 
 import java.nio.file.*;
 import java.nio.file.attribute.*;
+import java.nio.file.spi.FileSystemProvider;
 import java.io.IOException;
 
 /**
@@ -38,6 +39,10 @@ public class BsdFileSystemProvider exten
         super();
     }
 
+    public BsdFileSystemProvider(FileSystemProvider f) {
+        super();
+    }
+
     @Override
     BsdFileSystem newFileSystem(String dir) {
         return new BsdFileSystem(this, dir);
