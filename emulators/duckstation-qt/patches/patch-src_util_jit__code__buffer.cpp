$NetBSD: patch-src_util_jit__code__buffer.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/util/jit_code_buffer.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/util/jit_code_buffer.cpp
@@ -53,7 +53,7 @@ bool JitCodeBuffer::Allocate(u32 size /*
     Log_ErrorPrintf("VirtualAlloc(RWX, %u) for internal buffer failed: %u", m_total_size, GetLastError());
     return false;
   }
-#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__HAIKU__) || defined(__FreeBSD__)
+#else
   int flags = MAP_PRIVATE | MAP_ANONYMOUS;
 #if defined(__APPLE__) && defined(__aarch64__)
   // MAP_JIT and toggleable write protection is required on Apple Silicon.
@@ -66,8 +66,6 @@ bool JitCodeBuffer::Allocate(u32 size /*
     Log_ErrorPrintf("mmap(RWX, %u) for internal buffer failed: %d", m_total_size, errno);
     return false;
   }
-#else
-  return false;
 #endif
 
   m_free_code_ptr = m_code_ptr;
@@ -113,7 +111,7 @@ bool JitCodeBuffer::Initialize(void* buf
 
   m_code_ptr = static_cast<u8*>(buffer);
   m_old_protection = static_cast<u32>(old_protect);
-#elif defined(__linux__) || defined(__ANDROID__) || defined(__APPLE__) || defined(__HAIKU__) || defined(__FreeBSD__)
+#else
   if (mprotect(buffer, size, PROT_READ | PROT_WRITE | PROT_EXEC) != 0)
   {
     Log_ErrorPrintf("mprotect(RWX) for external buffer failed: %d", errno);
@@ -133,8 +131,6 @@ bool JitCodeBuffer::Initialize(void* buf
   // reasonable default?
   m_code_ptr = static_cast<u8*>(buffer);
   m_old_protection = PROT_READ | PROT_WRITE;
-#else
-  m_code_ptr = nullptr;
 #endif
 
   if (!m_code_ptr)
@@ -298,4 +294,4 @@ void JitCodeBuffer::WriteProtect(bool en
   pthread_jit_write_protect_np(enabled ? 1 : 0);
 }
 
-#endif
\ No newline at end of file
+#endif
