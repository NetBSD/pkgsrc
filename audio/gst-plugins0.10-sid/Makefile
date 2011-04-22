# $NetBSD: Makefile,v 1.4 2011/04/22 13:45:22 obache Exp $
#

GST_PLUGINS0.10_NAME=	sid
GST_PLUGINS0.10_DIRS=	ext/sidplay
GST_PLUGINS0.10_FLAGS=	sidplay

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
