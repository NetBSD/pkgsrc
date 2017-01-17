$NetBSD: patch-OMXAudio.cpp,v 1.1 2017/01/17 07:33:50 skrll Exp $

--- OMXAudio.cpp.orig	2016-10-10 15:38:42.000000000 +0000
+++ OMXAudio.cpp
@@ -585,7 +585,7 @@ bool COMXAudio::Initialize(OMXClock *clo
     }
 
     omx_buffer->nOffset = 0;
-    omx_buffer->nFilledLen  = std::min(sizeof(m_wave_header), omx_buffer->nAllocLen);
+    omx_buffer->nFilledLen  = std::min(sizeof(m_wave_header), (size_t)omx_buffer->nAllocLen);
 
     memset((unsigned char *)omx_buffer->pBuffer, 0x0, omx_buffer->nAllocLen);
     memcpy((unsigned char *)omx_buffer->pBuffer, &m_wave_header, omx_buffer->nFilledLen);
