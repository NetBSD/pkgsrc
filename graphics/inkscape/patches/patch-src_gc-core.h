$NetBSD: patch-src_gc-core.h,v 1.1 2014/04/17 06:20:27 wiz Exp $

    Committer: Johan B. C. Engelen
    Date: 2014-01-12 21:00:46 UTC
    Revision ID: j.b.c.engelen@alumnus.utwente.nl-20140112210046-w4k02e3v5wkwg2za

https://launchpad.net/bugs/1265072
fix build with boehm-gc 7.4.0+ (patch by Vladimir Smirnov, slightly modified by me)


--- src/gc-core.h.orig	2012-02-14 03:22:17.000000000 +0000
+++ src/gc-core.h
@@ -57,7 +57,7 @@ struct Ops {
                                            CleanupFunc *old_func,
                                            void **old_data);
     int (*general_register_disappearing_link)(void **p_ptr,
-                                              void *base);
+                                              void const *base);
     int (*unregister_disappearing_link)(void **p_ptr);
     std::size_t (*get_heap_size)();
     std::size_t (*get_free_bytes)();
