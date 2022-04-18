# $NetBSD: Makefile,v 1.17 2022/04/18 19:10:22 adam Exp $
#

GST_PLUGINS0.10_NAME=	sid
GST_PLUGINS0.10_DIRS=	ext/sidplay
GST_PLUGINS0.10_FLAGS=	sidplay
PKGREVISION=		8

USE_LANGUAGES=	c c++

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
