$NetBSD: patch-deps_v8_src_base_platform_platform-freebsd.cc,v 1.1 2019/12/09 20:05:40 adam Exp $

Overlapping variables, taken from https://github.com/joyent/node/issues/9175

--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2018-04-24 14:41:24.000000000 +0000
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -45,10 +45,10 @@ static unsigned StringToLong(char* buffe
 }
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
-  std::vector<SharedLibraryAddress> result;
+  std::vector<SharedLibraryAddress> address_result;
   static const int MAP_LENGTH = 1024;
   int fd = open("/proc/self/maps", O_RDONLY);
-  if (fd < 0) return result;
+  if (fd < 0) return address_result;
   while (true) {
     char addr_buffer[11];
     addr_buffer[0] = '0';
@@ -78,10 +78,10 @@ std::vector<OS::SharedLibraryAddress> OS
     // There may be no filename in this line.  Skip to next.
     if (start_of_path == nullptr) continue;
     buffer[bytes_read] = 0;
-    result.push_back(SharedLibraryAddress(start_of_path, start, end));
+    address_result.push_back(SharedLibraryAddress(start_of_path, start, end));
   }
   close(fd);
-  return result;
+  return address_result;
 }
 
 void OS::SignalCodeMovingGC() {}
