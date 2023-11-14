$NetBSD: patch-src_util_memory__arena.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/util/memory_arena.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/util/memory_arena.cpp
@@ -16,7 +16,7 @@ Log_SetChannel(Common::MemoryArena);
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <unistd.h>
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#else
 #include <cerrno>
 #include <fcntl.h>
 #include <sys/mman.h>
@@ -76,16 +76,14 @@ void* MemoryArena::FindBaseAddressForMap
   base_address = VirtualAlloc(nullptr, size, MEM_RESERVE, PAGE_READWRITE);
   if (base_address)
     VirtualFree(base_address, 0, MEM_RELEASE);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
-  base_address = mmap(nullptr, size, PROT_NONE, MAP_ANON | MAP_PRIVATE, -1, 0);
-  if (base_address)
-    munmap(base_address, size);
 #elif defined(__ANDROID__)
   base_address = mmap(nullptr, size, PROT_NONE, MAP_ANON | MAP_SHARED, -1, 0);
   if (base_address)
     munmap(base_address, size);
 #else
-  base_address = nullptr;
+  base_address = mmap(nullptr, size, PROT_NONE, MAP_ANON | MAP_PRIVATE, -1, 0);
+  if (base_address)
+    munmap(base_address, size);
 #endif
 
   if (!base_address)
@@ -110,13 +108,11 @@ static std::string GetFileMappingName()
 {
 #if defined(_WIN32)
   const unsigned pid = GetCurrentProcessId();
-#elif defined(__ANDROID__) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
-  const unsigned pid = static_cast<unsigned>(getpid());
 #else
-#error Unknown platform.
+  const unsigned pid = static_cast<unsigned>(getpid());
 #endif
 
-  const std::string ret(StringUtil::StdStringFromFormat("duckstation_%u", pid));
+  const std::string ret(StringUtil::StdStringFromFormat("/duckstation_%u", pid));
   Log_InfoPrintf("File mapping name: %s", ret.c_str());
   return ret;
 }
@@ -176,11 +172,11 @@ bool MemoryArena::Create(size_t size, bo
   m_writable = writable;
   m_executable = executable;
   return true;
-#elif defined(__APPLE__) || defined(__FreeBSD__)
-#if defined(__APPLE__)
-  m_shmem_fd = shm_open(file_mapping_name.c_str(), O_CREAT | O_EXCL | (writable ? O_RDWR : O_RDONLY), 0600);
 #else
+#ifdef SHM_ANON
   m_shmem_fd = shm_open(SHM_ANON, O_CREAT | O_EXCL | (writable ? O_RDWR : O_RDONLY), 0600);
+#else
+  m_shmem_fd = shm_open(file_mapping_name.c_str(), O_CREAT | O_EXCL | (writable ? O_RDWR : O_RDONLY), 0600);
 #endif
 
   if (m_shmem_fd < 0)
@@ -189,7 +185,7 @@ bool MemoryArena::Create(size_t size, bo
     return false;
   }
 
-#ifdef __APPLE__
+#ifndef SHM_ANON
   // we're not going to be opening this mapping in other processes, so remove the file
   shm_unlink(file_mapping_name.c_str());
 #endif
@@ -205,8 +201,6 @@ bool MemoryArena::Create(size_t size, bo
   m_writable = writable;
   m_executable = executable;
   return true;
-#else
-  return false;
 #endif
 }
 
@@ -218,7 +212,7 @@ void MemoryArena::Destroy()
     CloseHandle(m_file_handle);
     m_file_handle = nullptr;
   }
-#elif defined(__linux__) || defined(__FreeBSD__)
+#elif defined(__linux__) || defined(SHM_ANON)
   if (m_shmem_fd > 0)
   {
     close(m_shmem_fd);
@@ -256,14 +250,12 @@ void* MemoryArena::CreateViewPtr(size_t 
     MapViewOfFileEx(m_file_handle, desired_access, Truncate32(offset >> 32), Truncate32(offset), size, fixed_address);
   if (!base_pointer)
     return nullptr;
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#else
   const int flags = (fixed_address != nullptr) ? (MAP_SHARED | MAP_FIXED) : MAP_SHARED;
   const int prot = PROT_READ | (writable ? PROT_WRITE : 0) | (executable ? PROT_EXEC : 0);
   base_pointer = mmap(fixed_address, size, prot, flags, m_shmem_fd, static_cast<off_t>(offset));
   if (base_pointer == reinterpret_cast<void*>(-1))
     return nullptr;
-#else
-  return nullptr;
 #endif
 
   m_num_views.fetch_add(1);
@@ -274,10 +266,8 @@ bool MemoryArena::FlushViewPtr(void* add
 {
 #if defined(_WIN32)
   return FlushViewOfFile(address, size);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
-  return (msync(address, size, 0) >= 0);
 #else
-  return false;
+  return (msync(address, size, 0) >= 0);
 #endif
 }
 
@@ -286,10 +276,8 @@ bool MemoryArena::ReleaseViewPtr(void* a
   bool result;
 #if defined(_WIN32)
   result = static_cast<bool>(UnmapViewOfFile(address));
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
-  result = (munmap(address, size) >= 0);
 #else
-  result = false;
+  result = (munmap(address, size) >= 0);
 #endif
 
   if (!result)
@@ -308,14 +296,12 @@ void* MemoryArena::CreateReservedPtr(siz
   void* base_pointer;
 #if defined(_WIN32)
   base_pointer = VirtualAlloc(fixed_address, size, MEM_RESERVE, PAGE_NOACCESS);
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#else
   const int flags =
     (fixed_address != nullptr) ? (MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED) : (MAP_PRIVATE | MAP_ANONYMOUS);
   base_pointer = mmap(fixed_address, size, PROT_NONE, flags, -1, 0);
   if (base_pointer == reinterpret_cast<void*>(-1))
     return nullptr;
-#else
-  return nullptr;
 #endif
 
   m_num_views.fetch_add(1);
@@ -327,10 +313,8 @@ bool MemoryArena::ReleaseReservedPtr(voi
   bool result;
 #if defined(_WIN32)
   result = static_cast<bool>(VirtualFree(address, 0, MEM_RELEASE));
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
-  result = (munmap(address, size) >= 0);
 #else
-  result = false;
+  result = (munmap(address, size) >= 0);
 #endif
 
   if (!result)
@@ -354,11 +338,9 @@ bool MemoryArena::SetPageProtection(void
   DWORD old_protect;
   return static_cast<bool>(
     VirtualProtect(address, length, protection_table[readable][writable][executable], &old_protect));
-#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__)
+#else
   const int prot = (readable ? PROT_READ : 0) | (writable ? PROT_WRITE : 0) | (executable ? PROT_EXEC : 0);
   return (mprotect(address, length, prot) >= 0);
-#else
-  return false;
 #endif
 }
 
