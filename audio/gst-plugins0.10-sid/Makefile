# $NetBSD: Makefile,v 1.14 2020/11/05 09:07:27 ryoon Exp $
#

GST_PLUGINS0.10_NAME=	sid
GST_PLUGINS0.10_DIRS=	ext/sidplay
GST_PLUGINS0.10_FLAGS=	sidplay
PKGREVISION=		5

USE_LANGUAGES=	c c++

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
