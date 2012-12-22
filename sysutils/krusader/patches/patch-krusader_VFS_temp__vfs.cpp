$NetBSD: patch-krusader_VFS_temp__vfs.cpp,v 1.1 2012/12/22 02:31:33 joerg Exp $

--- krusader/VFS/temp_vfs.cpp.orig	2012-12-22 01:32:42.000000000 +0000
+++ krusader/VFS/temp_vfs.cpp
@@ -40,8 +40,8 @@
 #include "../resources.h"
 #include "../krservices.h"
 
-temp_vfs::temp_vfs( QString origin, QString type, QWidget* panel, bool ):
-          normal_vfs(panel){
+temp_vfs::temp_vfs( QString origin, QString type_, QWidget* panel, bool ):
+          normal_vfs(panel), type(type_){
   vfs_type=TEMP;
    // first we need to create a temp diretory
   tmpDir = krApp->getTempDir();
@@ -56,7 +56,7 @@ temp_vfs::temp_vfs( QString origin, QStr
 }
 
 temp_vfs::~temp_vfs(){
-	if( vfs_type == "-iso" ){
+	if( type == "-iso" ){
 		// unmount the ISO image
     KShellProcess umount;
 		umount << "umount -f" << tmpDir;
