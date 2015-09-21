$NetBSD: patch-src_api_nodejs_sqlrelay.cpp,v 1.1 2015/09/21 17:46:36 fhajny Exp $

Add support for nodejs>=4.0.0.

--- src/api/nodejs/sqlrelay.cpp.orig	2015-07-05 02:55:20.000000000 +0000
+++ src/api/nodejs/sqlrelay.cpp
@@ -13,7 +13,7 @@ using namespace v8;
 using namespace node;
 
 // macros to deal with differences between major versions of node.js
-#if NODE_MINOR_VERSION >= 12
+#if NODE_MAJOR_VERSION >= 4 || ( NODE_MAJOR_VERSION < 1 && NODE_MINOR_VERSION >= 12 )
 
 	#define RET void
 	#define ARGS FunctionCallbackInfo<Value>
@@ -84,7 +84,7 @@ using namespace node;
 #define toString(arg) ((arg->IsNull())?NULL:*(String::Utf8Value(arg)))
 #define toArray(arg) Handle<Array>::Cast(arg);
 
-#if NODE_MINOR_VERSION >= 12
+#if NODE_MAJOR_VERSION >= 4 || ( NODE_MAJOR_VERSION < 1 && NODE_MINOR_VERSION >= 12 )
 	#define throwWrongNumberOfArguments() isolate->ThrowException(Exception::TypeError(newString("Wrong number of arguments")))
 	#define throwInvalidArgumentType() isolate->ThrowException(Exception::TypeError(newString("Invalid argument type")))
 #else
