$NetBSD: patch-src_af_util_xp_ut__misc.cpp,v 1.1 2015/09/13 21:32:13 nros Exp $

--- src/af/util/xp/ut_misc.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/xp/ut_misc.cpp
@@ -589,7 +589,7 @@ const gchar ** UT_splitPropsToArray(gcha
 		}
 
 		char * semi = NULL;
-		const char * p = pProps;
+		char * p = pProps;
  		while((semi = (char *) strchr(p, ';')))
 		{
 			*semi = 0;
@@ -603,7 +603,7 @@ const gchar ** UT_splitPropsToArray(gcha
 		const gchar ** pPropsArray = new const gchar *[2 * iPropCount + 1];
 		UT_return_val_if_fail( pPropsArray, NULL );
 	
-		const char * pStart = pProps;
+		char * pStart = pProps;
 
 		// we want to include the 0-terminator
 		for(i = 0; i <= iLen; i++)
