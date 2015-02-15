$NetBSD: patch-src_main.cpp,v 1.1 2015/02/15 14:09:38 ryoon Exp $

https://sourceforge.net/p/xfe/bugs/198/

--- src/main.cpp.orig	2014-12-05 12:13:04.000000000 +0000
+++ src/main.cpp
@@ -301,13 +301,14 @@ int main(int argc,char *argv[])
   	textdomain(PACKAGE);
 #endif
 
+	FXString cmd;
 #if defined(linux)
 
     // For package query on Linux systems, try to guess if the default package format is deb or rpm:
     //   - if dpkg exists then the system uses deb packages
     //   - else if rpm exists, then the system uses rpm packages
 	//   - else another (unsupported) package manager is used
-	FXString cmd, str;
+	FXString str;
 
 	cmd="dpkg --version";
 	str=getCommandOutput(cmd);
