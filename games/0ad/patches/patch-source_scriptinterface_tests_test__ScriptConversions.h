$NetBSD: patch-source_scriptinterface_tests_test__ScriptConversions.h,v 1.1 2023/05/04 15:20:52 nikita Exp $


--- source/scriptinterface/tests/test_ScriptConversions.h.orig	2023-05-04 01:07:22.308333403 +0200
+++ source/scriptinterface/tests/test_ScriptConversions.h	2023-05-04 01:07:53.059298729 +0200
@@ -208,7 +208,7 @@
 		JS::RootedValue testNANVal(rq.cx);
 		Script::ToJSVal(rq, &testNANVal, NAN);
 		TS_ASSERT(Script::FromJSVal(rq, testNANVal, f));
-		TS_ASSERT(isnan(f));
+		TS_ASSERT(std::isnan(f));
 	}
 
 	// NOTE: fixed and vector conversions are defined in simulation2/scripting/EngineScriptConversions.cpp
