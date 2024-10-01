$NetBSD: patch-js_public_Utility.h,v 1.1 2024/10/01 14:21:37 ryoon Exp $

--- js/public/Utility.h.orig	2024-07-15 21:09:40.000000000 +0000
+++ js/public/Utility.h
@@ -478,9 +478,6 @@ static inline void js_free(void* p) {
 #define JS_DECLARE_NEW_METHODS(NEWNAME, ALLOCATOR, QUALIFIERS)              \
   template <class T, typename... Args>                                      \
   QUALIFIERS T* MOZ_HEAP_ALLOCATOR NEWNAME(Args&&... args) {                \
-    static_assert(                                                          \
-        alignof(T) <= alignof(max_align_t),                                 \
-        "over-aligned type is not supported by JS_DECLARE_NEW_METHODS");    \
     void* memory = ALLOCATOR(sizeof(T));                                    \
     return MOZ_LIKELY(memory) ? new (memory) T(std::forward<Args>(args)...) \
                               : nullptr;                                    \
@@ -497,9 +494,6 @@ static inline void js_free(void* p) {
 #define JS_DECLARE_NEW_ARENA_METHODS(NEWNAME, ALLOCATOR, QUALIFIERS)           \
   template <class T, typename... Args>                                         \
   QUALIFIERS T* MOZ_HEAP_ALLOCATOR NEWNAME(arena_id_t arena, Args&&... args) { \
-    static_assert(                                                             \
-        alignof(T) <= alignof(max_align_t),                                    \
-        "over-aligned type is not supported by JS_DECLARE_NEW_ARENA_METHODS"); \
     void* memory = ALLOCATOR(arena, sizeof(T));                                \
     return MOZ_LIKELY(memory) ? new (memory) T(std::forward<Args>(args)...)    \
                               : nullptr;                                       \
