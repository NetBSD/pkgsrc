# $NetBSD: Makefile,v 1.1 2012/11/29 09:18:57 ryoon Exp $
#

GST_PLUGINS1_NAME=	sid
GST_PLUGINS1_DIRS=	ext/sidplay
GST_PLUGINS1_FLAGS=	sidplay

USE_LANGUAGES=	c c++

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
