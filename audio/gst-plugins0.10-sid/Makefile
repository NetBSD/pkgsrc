# $NetBSD: Makefile,v 1.8 2012/03/03 00:14:24 wiz Exp $
#

GST_PLUGINS0.10_NAME=	sid
GST_PLUGINS0.10_DIRS=	ext/sidplay
GST_PLUGINS0.10_FLAGS=	sidplay

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
