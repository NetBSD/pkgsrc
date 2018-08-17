$NetBSD: patch-src_burn_snd_msm6295.cpp,v 1.1 2018/08/17 12:54:48 nia Exp $

"Fixing some sound interpolation issue in nec cpu"

Upstream commit: 458002c9ce850864952ff5cc62818315d788957f

--- src/burn/snd/msm6295.cpp.orig	2018-04-08 06:33:58.000000000 +0000
+++ src/burn/snd/msm6295.cpp
@@ -302,7 +302,7 @@ static void MSM6295Render_Cubic(INT32 nC
 					pChannelInfo->nBufPos = 4;
 				}
 
-				nOutput += INTERPOLATE4PS_16BIT(nFractionalPosition,
+				nOutput += INTERPOLATE4PS_16BIT(nFractionalPosition & 0x0FFF,
 												MSM6295ChannelData[nChip][nChannel][pChannelInfo->nBufPos - 4],
 												MSM6295ChannelData[nChip][nChannel][pChannelInfo->nBufPos - 3],
 												MSM6295ChannelData[nChip][nChannel][pChannelInfo->nBufPos - 2],
