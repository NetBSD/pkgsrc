$NetBSD: patch-utils_datetime.cpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/datetime.cpp.orig	2013-05-06 08:18:02.000000000 +0000
+++ utils/datetime.cpp
@@ -183,7 +183,7 @@ struct timestamp::impl {
 /// Constructs a new timestamp.
 ///
 /// \param pimpl_ An existing impl representation.
-datetime::timestamp::timestamp(std::tr1::shared_ptr< impl > pimpl_) :
+datetime::timestamp::timestamp(shared_ptr< impl > pimpl_) :
     _pimpl(pimpl_)
 {
 }
@@ -201,7 +201,7 @@ datetime::timestamp::from_microseconds(c
     ::timeval data;
     data.tv_sec = static_cast< time_t >(value / 1000000);
     data.tv_usec = static_cast< suseconds_t >(value % 1000000);
-    return timestamp(std::tr1::shared_ptr< impl >(new impl(data)));
+    return timestamp(shared_ptr< impl >(new impl(data)));
 }
 
 
@@ -257,7 +257,7 @@ datetime::timestamp::from_values(const i
     ::timeval data;
     data.tv_sec = ::mktime(&timedata);
     data.tv_usec = static_cast< suseconds_t >(microsecond);
-    return timestamp(std::tr1::shared_ptr< impl >(new impl(data)));
+    return timestamp(shared_ptr< impl >(new impl(data)));
 }
 
 
@@ -276,7 +276,7 @@ datetime::timestamp::now(void)
         INV(ret != -1);
     }
 
-    return timestamp(std::tr1::shared_ptr< impl >(new impl(data)));
+    return timestamp(shared_ptr< impl >(new impl(data)));
 }
 
 
