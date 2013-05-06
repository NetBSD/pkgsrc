$NetBSD: patch-backends_mixer__backend.cpp,v 1.1 2013/05/06 14:54:57 joerg Exp $

--- backends/mixer_backend.cpp.orig	2013-05-04 01:47:44.000000000 +0000
+++ backends/mixer_backend.cpp
@@ -237,7 +237,7 @@ void Mixer_Backend::readSetFromHW()
  */
 shared_ptr<MixDevice> Mixer_Backend::recommendedMaster()
 {
-	if ( m_recommendedMaster != 0 )
+	if ( m_recommendedMaster != nullptr )
 	{
 		// Backend has set a recommended master. Thats fine. Using it.
 		return m_recommendedMaster;
