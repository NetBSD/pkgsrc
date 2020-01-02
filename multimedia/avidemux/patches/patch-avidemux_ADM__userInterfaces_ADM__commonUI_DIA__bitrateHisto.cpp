$NetBSD: patch-avidemux_ADM__userInterfaces_ADM__commonUI_DIA__bitrateHisto.cpp,v 1.1 2020/01/02 19:47:04 rhialto Exp $

gcc7: error: call of overloaded 'abs(__uint32_t)' is ambiguous
so make the values signed so that a difference can properly be determined.

--- avidemux/ADM_userInterfaces/ADM_commonUI/DIA_bitrateHisto.cpp.orig	2008-04-03 18:19:06.000000000 +0000
+++ avidemux/ADM_userInterfaces/ADM_commonUI/DIA_bitrateHisto.cpp
@@ -50,7 +50,7 @@ uint32_t maxBFrame=0;
 	// 1st compute the total
 	
 	max=0;
-	if(!(frameEnd>frameStart) || abs(frameStart-frameEnd)<5)
+	if(!(frameEnd>frameStart) || abs((int64_t)frameStart-(int64_t)frameEnd)<5)
 	{
           GUI_Error_HIG(QT_TR_NOOP("No data"), NULL);
 		return ;
