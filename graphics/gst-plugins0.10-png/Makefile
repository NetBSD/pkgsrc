# $NetBSD: Makefile,v 1.9 2011/04/22 13:45:21 obache Exp $
#

GST_PLUGINS0.10_NAME=	png
GST_PLUGINS0.10_DIRS=	ext/libpng
GST_PLUGINS0.10_FLAGS=	libpng

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
