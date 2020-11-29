$NetBSD: patch-gr-digital_lib_map__bb__impl.cc,v 1.1 2020/11/29 22:35:47 dbj Exp $

Add missing definition for a static class member
fixed from upstream rev 3282fa7 
https://github.com/gnuradio/gnuradio/pull/3677

--- gr-digital/lib/map_bb_impl.cc.orig	2020-04-08 17:21:10.000000000 +0000
+++ gr-digital/lib/map_bb_impl.cc
@@ -30,6 +30,8 @@
 namespace gr {
 namespace digital {
 
+constexpr size_t map_bb_impl::s_map_size;
+
 map_bb::sptr map_bb::make(const std::vector<int>& map)
 {
     return gnuradio::get_initial_sptr(new map_bb_impl(map));
