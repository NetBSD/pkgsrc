$NetBSD: patch-storage_ndb_src_mgmapi_ndb__logevent.cpp,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- storage/ndb/src/mgmapi/ndb_logevent.cpp.orig	2021-09-14 09:08:08.000000000 +0000
+++ storage/ndb/src/mgmapi/ndb_logevent.cpp
@@ -519,6 +519,9 @@ int ndb_logevent_get_next(const NdbLogEv
   int rc = ndb_logevent_get_next2(h,
                                   dst,
                                   timeout_in_milliseconds);
+
+#pragma GCC diagnostic ignored "-Wnarrowing"
+
   if (rc == 1)
   {
     /**
