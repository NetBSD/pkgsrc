$NetBSD: patch-lib_usrp_b200_b200__io__impl.cpp,v 1.1 2015/04/23 18:26:30 joerg Exp $

--- lib/usrp/b200/b200_io_impl.cpp.orig	2015-04-23 14:23:25.000000000 +0000
+++ lib/usrp/b200/b200_io_impl.cpp
@@ -184,7 +184,7 @@ boost::optional<uhd::msg_task::msg_type_
 {
     managed_recv_buffer::sptr buff = xport->get_recv_buff();
     if (not buff or buff->size() < 8)
-        return NULL;
+        return boost::none;
 
     const boost::uint32_t sid = uhd::wtohx(buff->cast<const boost::uint32_t *>()[1]);
     switch (sid) {
@@ -248,7 +248,7 @@ boost::optional<uhd::msg_task::msg_type_
     default:
         UHD_MSG(error) << "Got a ctrl packet with unknown SID " << sid << std::endl;
     }
-    return NULL;
+    return boost::none;
 }
 
 /***********************************************************************
