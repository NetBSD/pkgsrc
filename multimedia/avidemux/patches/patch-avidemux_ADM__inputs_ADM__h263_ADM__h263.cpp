$NetBSD: patch-avidemux_ADM__inputs_ADM__h263_ADM__h263.cpp,v 1.1 2020/01/02 19:47:04 rhialto Exp $

gcc7: ambiguous call to abs(uint32_t) but can't be negative
(even if maybe that might have been intended).

--- avidemux/ADM_inputs/ADM_h263/ADM_h263.cpp.orig	2008-06-24 19:46:05.000000000 +0000
+++ avidemux/ADM_inputs/ADM_h263/ADM_h263.cpp
@@ -169,7 +169,7 @@ uint8_t    h263Header::open(const char *
 		delta &=0xff;
 		if(!nbImg) delta=0;
 		//++++++++++++++PTYPE++++++++++++
-		if(((word&0xc0)==0x80) && ( abs(delta)<MAX_DELTA))
+		if(((word&0xc0)==0x80) && ( delta<MAX_DELTA))
 		{
 		last_pts=pts;
 		nbImg++;
