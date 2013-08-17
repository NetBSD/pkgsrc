$NetBSD: patch-gnuradio-core_src_lib_io_ppio__ppdev.h,v 1.1 2013/08/17 11:17:08 joerg Exp $

--- gnuradio-core/src/lib/io/ppio_ppdev.h.orig	2013-08-15 17:47:21.000000000 +0000
+++ gnuradio-core/src/lib/io/ppio_ppdev.h
@@ -34,7 +34,7 @@ typedef boost::shared_ptr<ppio_ppdev> pp
  */
 
 class ppio_ppdev : public ppio {
-  friend ppio_ppdev_sptr make_ppio_ppdev (int which = 0);
+  friend ppio_ppdev_sptr make_ppio_ppdev (int which);
   ppio_ppdev (int which = 0);
 
  public:
