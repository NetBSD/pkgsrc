$NetBSD: patch-libgrive_src_protocol_Json.cc,v 1.3 2020/09/14 18:20:57 joerg Exp $

Update for json-c 0.14 and later
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
@@ -254,7 +282,7 @@ Json Json::operator[]( const std::size_t
 bool Json::Has( const std::string& key ) const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_object_get_ex( m_json, key.c_str(), 0 ) == TRUE ;
+	return ::json_object_object_get_ex( m_json, key.c_str(), 0 );
 }
 
 bool Json::Get( const std::string& key, Json& json ) const
@@ -294,14 +322,14 @@ void Json::Add( const Json& json )
 bool Json::Bool() const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_get_boolean( m_json ) == TRUE ;
+	return ::json_object_get_boolean( m_json );
 }
 
 template <>
 bool Json::Is<bool>() const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_is_type( m_json, json_type_boolean ) == TRUE ;
+	return ::json_object_is_type( m_json, json_type_boolean );
 }
 
 template <>
@@ -320,7 +348,7 @@ template <>
 bool Json::Is<std::string>() const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_is_type( m_json, json_type_string ) == TRUE ;
+	return ::json_object_is_type( m_json, json_type_string );
 }
 
 template <>
@@ -339,7 +367,7 @@ template <>
 bool Json::Is<int>() const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_is_type( m_json, json_type_int ) == TRUE ;
+	return ::json_object_is_type( m_json, json_type_int );
 }
 
 template <>
@@ -402,7 +430,7 @@ template <>
 bool Json::Is<Json::Object>() const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_is_type( m_json, json_type_object ) == TRUE ;
+	return ::json_object_is_type( m_json, json_type_object );
 }
 
 template <>
@@ -426,7 +454,7 @@ template <>
 bool Json::Is<Json::Array>() const
 {
 	assert( m_json != 0 ) ;
-	return ::json_object_is_type( m_json, json_type_array ) == TRUE ;
+	return ::json_object_is_type( m_json, json_type_array );
 }
 
 template <>
