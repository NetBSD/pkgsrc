$NetBSD: patch-glib_poppler-page.cc,v 1.1 2026/07/04 21:57:33 prlw1 Exp $

PopplerPage instances are created with g_object_new(), which only
zero-initializes the instance memory and never runs a C++ constructor
for members. Since commit e3d56a0e ("glib: add a lock in PopplerPage
to make TextPage computation thread-safe", 26.05.0) the struct gained a
std::mutex member, but poppler_page_init() was empty, leaving the mutex
as an all-zero pthread_mutex_t.

https://gitlab.freedesktop.org/poppler/poppler/-/commit/08f4bca6a669f9fce75dbab743db559a86591738

--- glib/poppler-page.cc.orig	2026-06-02 20:32:51.000000000 +0000
+++ glib/poppler-page.cc
@@ -1134,7 +1134,11 @@ static void poppler_page_class_init(PopplerPageClass *
     g_object_class_install_property(G_OBJECT_CLASS(klass), PROP_LABEL, g_param_spec_string("label", "Page Label", "The label of the page", nullptr, G_PARAM_READABLE));
 }
 
-static void poppler_page_init(PopplerPage * /*page*/) { }
+static void poppler_page_init(PopplerPage * page)
+{
+    // GObject zero-initializes instance memory; construct the C++ mutex member explicitly.
+    new (&page->mutex) std::mutex();
+}
 
 /**
  * poppler_page_get_link_mapping:
