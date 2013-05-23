$NetBSD: patch-backends_mixer__mpris2.cpp,v 1.3 2013/05/23 15:06:48 joerg Exp $

--- backends/mixer_mpris2.cpp.orig	2013-05-04 01:48:09.000000000 +0000
+++ backends/mixer_mpris2.cpp
@@ -394,7 +394,7 @@ void Mixer_MPRIS2::newMediaPlayer(QStrin
 			QString id = ( lastDot == -1 ) ? name : name.mid(lastDot+1);
 			apps.remove(id);
 			shared_ptr<MixDevice> md = m_mixDevices.get(id);
-			if (md != 0)
+			if (md)
 			{
 				// We know about the player that is unregistering => remove internally
 				md->close();
