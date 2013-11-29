$NetBSD: patch-mozilla_memory_mozalloc_mozalloc.h,v 1.1 2013/11/29 12:58:52 joerg Exp $

--- mozilla/memory/mozalloc/mozalloc.h.orig	2013-01-05 14:22:31.000000000 +0000
+++ mozilla/memory/mozalloc/mozalloc.h
@@ -68,15 +68,6 @@
 #  define MOZALLOC_EXPORT
 #endif
 
-
-#if defined(NS_ALWAYS_INLINE)
-#  define MOZALLOC_INLINE NS_ALWAYS_INLINE inline
-#elif defined(HAVE_FORCEINLINE)
-#  define MOZALLOC_INLINE __forceinline
-#else
-#  define MOZALLOC_INLINE inline
-#endif
-
 /* Workaround build problem with Sun Studio 12 */
 #if defined(__SUNPRO_C) || defined(__SUNPRO_CC)
 #  undef NS_WARN_UNUSED_RESULT
@@ -198,15 +189,6 @@ MOZALLOC_EXPORT void* moz_valloc(size_t 
  * that |::operator new() throw(std::bad_alloc)| will never return NULL.
  */
 
-/* NB: This is defined just to silence vacuous warnings about symbol
- * visibility on OS X/gcc. These symbols are force-inline and not
- * exported. */
-#if defined(XP_MACOSX)
-#  define MOZALLOC_EXPORT_NEW MOZALLOC_EXPORT
-#else
-#  define MOZALLOC_EXPORT_NEW
-#endif
-
 #if defined(ANDROID) || defined(_MSC_VER)
 /*
  * Android doesn't fully support exceptions, so its <new> header
@@ -222,53 +204,29 @@ MOZALLOC_EXPORT void* moz_valloc(size_t 
 
 #define MOZALLOC_THROW_BAD_ALLOC MOZALLOC_THROW_BAD_ALLOC_IF_HAS_EXCEPTIONS
 
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new(size_t size) MOZALLOC_THROW_BAD_ALLOC
-{
-    return moz_xmalloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new(size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new[](size_t size) MOZALLOC_THROW_BAD_ALLOC
-{
-    return moz_xmalloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void* operator new[](size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete(void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete(void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete[](void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
-
-MOZALLOC_EXPORT_NEW MOZALLOC_INLINE
-void operator delete[](void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_free(ptr);
-}
+MOZALLOC_EXPORT
+void* operator new(size_t size) MOZALLOC_THROW_BAD_ALLOC;
+
+MOZALLOC_EXPORT
+void* operator new(size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size) MOZALLOC_THROW_BAD_ALLOC;
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr, const std::nothrow_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
 
 
 /*
@@ -296,29 +254,17 @@ struct MOZALLOC_EXPORT fallible_t { };
 
 } /* namespace mozilla */
 
-MOZALLOC_INLINE
-void* operator new(size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_INLINE
-void* operator new[](size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    return moz_malloc(size);
-}
-
-MOZALLOC_INLINE
-void operator delete(void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    moz_free(ptr);
-}
-
-MOZALLOC_INLINE
-void operator delete[](void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS
-{
-    moz_free(ptr);
-}
+MOZALLOC_EXPORT
+void* operator new(size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void* operator new[](size_t size, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete(void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
+
+MOZALLOC_EXPORT
+void operator delete[](void* ptr, const mozilla::fallible_t&) MOZALLOC_THROW_IF_HAS_EXCEPTIONS;
 
 #endif  /* ifdef __cplusplus */
 
