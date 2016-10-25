$NetBSD: patch-src_cares__wrap.cc,v 1.1 2016/10/25 19:54:00 fhajny Exp $

NetBSD has no AI_V4MAPPED.

--- src/cares_wrap.cc.orig	2015-03-31 22:13:01.000000000 +0000
+++ src/cares_wrap.cc
@@ -1301,8 +1301,10 @@ static void Initialize(Handle<Object> ta
               Integer::New(env->isolate(), AF_UNSPEC));
   target->Set(FIXED_ONE_BYTE_STRING(env->isolate(), "AI_ADDRCONFIG"),
               Integer::New(env->isolate(), AI_ADDRCONFIG));
+#if defined(AI_V4MAPPED)
   target->Set(FIXED_ONE_BYTE_STRING(env->isolate(), "AI_V4MAPPED"),
               Integer::New(env->isolate(), AI_V4MAPPED));
+#endif
 
   Local<FunctionTemplate> aiw =
       FunctionTemplate::New(env->isolate(), NewGetAddrInfoReqWrap);
