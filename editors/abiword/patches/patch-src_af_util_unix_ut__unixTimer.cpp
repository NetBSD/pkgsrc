$NetBSD: patch-src_af_util_unix_ut__unixTimer.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35476: Fix flicker and caret problems.

--- src/af/util/unix/ut_unixTimer.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/unix/ut_unixTimer.cpp
@@ -66,10 +66,11 @@ static int _Timer_Proc(void *p)
 	UT_ASSERT(pTimer);
 
 	xxx_UT_DEBUGMSG(("ut_unixTimer.cpp:  timer fired\n"));
-	
-	pTimer->fire();
-
-	return true;
+	if (pTimer) {
+		pTimer->fire();
+		return TRUE;
+	}
+	return 0;
 }
 
 UT_sint32 UT_UNIXTimer::set(UT_uint32 iMilliseconds)
