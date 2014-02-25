$NetBSD: patch-plugins_actor_corona_corona.cpp,v 1.1 2014/02/25 01:45:53 wiedi Exp $

fix "sqrt(int) is ambiguous" on SunOS
--- plugins/actor/corona/corona.cpp.orig	2006-02-05 18:47:26.000000000 +0000
+++ plugins/actor/corona/corona.cpp
@@ -118,7 +118,7 @@ bool Corona::setUpSurface(int width, int
 	}
 
 	// Change the number of particles
-	int newsize = (int) (::sqrt(m_width * m_height) * 3.0);
+	int newsize = (int) (::sqrt((double) (m_width * m_height)) * 3.0);
 	if (newsize < 2000) newsize = 2000;
 	int oldsize = (int) nbParticules;
 	nbParticules = newsize;
