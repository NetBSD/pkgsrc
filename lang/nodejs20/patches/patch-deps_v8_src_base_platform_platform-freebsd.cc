$NetBSD: patch-deps_v8_src_base_platform_platform-freebsd.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

Overlapping variables, taken from https://github.com/joyent/node/issues/9175

--- deps/v8/src/base/platform/platform-freebsd.cc.orig	2020-01-07 22:07:49.000000000 +0000
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -47,7 +47,7 @@ static unsigned StringToLong(char* buffe
 }
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
-  std::vector<SharedLibraryAddress> result;
+  std::vector<SharedLibraryAddress> address_result;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
   size_t miblen = sizeof(mib) / sizeof(mib[0]);
   size_t buffer_size;
@@ -80,7 +80,7 @@ std::vector<OS::SharedLibraryAddress> OS
           } else {
             lib_name = std::string(path);
           }
-          result.push_back(SharedLibraryAddress(
+          address_result.push_back(SharedLibraryAddress(
               lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
               reinterpret_cast<uintptr_t>(map->kve_end)));
         }
@@ -89,7 +89,7 @@ std::vector<OS::SharedLibraryAddress> OS
       }
     }
   }
-  return result;
+  return address_result;
 }
 
 void OS::SignalCodeMovingGC() {}
