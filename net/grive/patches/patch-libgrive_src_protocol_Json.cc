$NetBSD: patch-libgrive_src_protocol_Json.cc,v 1.2 2015/03/10 14:08:02 joerg Exp $

Update for json-c 0.11 and later
On NetBSD/ARM, int32_t is not long, so add template specialisation for that.

--- libgrive/src/protocol/Json.cc.orig	2013-05-02 16:40:04.000000000 +0000
+++ libgrive/src/protocol/Json.cc
@@ -29,8 +29,8 @@
 	#pragma warning(push)
 	#pragma warning(disable: 4005)
 #endif
-#include <json/json_tokener.h>
-#include <json/linkhash.h>
+#include <json-c/json_tokener.h>
+#include <json-c/linkhash.h>
 #ifdef _MSC_VER
 	#pragma warning(pop)
 #endif
@@ -107,6 +107,20 @@ Json::Json( const boost::int32_t& l ) :
 		) ;
 }
 
+#ifdef __arm__
+template <>
+Json::Json( const long& l ) :
+	m_json( ::json_object_new_int( l ) )
+{
+	if ( m_json == 0 )
+		BOOST_THROW_EXCEPTION(
+			Error()
+				<< JsonCApi_( "json_object_new_int" )
+				<< ValueErr( l )
+		) ;
+}
+#endif
+
 template <>
 Json::Json( const boost::int64_t& l ) :
 	m_json( ::json_object_new_int64( l ) )
@@ -131,6 +145,20 @@ Json::Json( const boost::uint32_t& l ) :
 		) ;
 }
 
+#ifdef __arm__
+template <>
+Json::Json( const unsigned long& l ) :
+	m_json( ::json_object_new_int( static_cast<int>(l) ) )
+{
+	if ( m_json == 0 )
+		BOOST_THROW_EXCEPTION(
+			Error()
+				<< JsonCApi_( "json_object_new_int" )
+				<< ValueErr( l )
+		) ;
+}
+#endif
+
 template <>
 Json::Json( const boost::uint64_t& l ) :
 	m_json( ::json_object_new_int64( l ) )
