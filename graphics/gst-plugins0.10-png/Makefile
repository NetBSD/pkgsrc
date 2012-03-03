# $NetBSD: Makefile,v 1.13 2012/03/03 00:14:25 wiz Exp $
#

GST_PLUGINS0.10_NAME=	png
GST_PLUGINS0.10_DIRS=	ext/libpng
GST_PLUGINS0.10_FLAGS=	libpng

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
