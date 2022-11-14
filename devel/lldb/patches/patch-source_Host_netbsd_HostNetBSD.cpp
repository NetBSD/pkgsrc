$NetBSD: patch-source_Host_netbsd_HostNetBSD.cpp,v 1.1 2022/11/14 18:46:39 adam Exp $

Fix build on NetBSD.

--- source/Host/netbsd/HostNetBSD.cpp.orig	2022-11-10 13:48:56.029150970 +0000
+++ source/Host/netbsd/HostNetBSD.cpp
@@ -109,7 +109,7 @@ static bool GetNetBSDProcessCPUType(Proc
         process_info.GetExecutableFile(), 0x20, 0);
     if (buffer_sp) {
       uint8_t exe_class = llvm::object::getElfArchType(
-                              {reinterpret_cast<char *>(buffer_sp->GetBytes()),
+                              {reinterpret_cast<const char *>(buffer_sp->GetBytes()),
                                size_t(buffer_sp->GetByteSize())})
                               .first;
 
