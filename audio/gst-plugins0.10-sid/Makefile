# $NetBSD: Makefile,v 1.10 2012/09/12 00:24:38 asau Exp $
#

GST_PLUGINS0.10_NAME=	sid
GST_PLUGINS0.10_DIRS=	ext/sidplay
GST_PLUGINS0.10_FLAGS=	sidplay
PKGREVISION=		1

USE_LANGUAGES=	c c++

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
