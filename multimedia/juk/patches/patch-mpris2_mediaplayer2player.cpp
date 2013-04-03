$NetBSD: patch-mpris2_mediaplayer2player.cpp,v 1.1 2013/04/03 11:13:09 markd Exp $

make sure we use juks tag.h

--- mpris2/mediaplayer2player.cpp.orig	2013-04-01 04:29:51.000000000 +0000
+++ mpris2/mediaplayer2player.cpp
@@ -24,7 +24,7 @@
 #include "coverinfo.h"
 #include "playlist.h"
 #include "playlistitem.h"
-#include "tag.h"
+#include "tagxx.h"
 #include "filehandle.h"
 
 #include <QCryptographicHash>
