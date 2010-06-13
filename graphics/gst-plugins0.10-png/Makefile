# $NetBSD: Makefile,v 1.5 2010/06/13 22:44:34 wiz Exp $
#

GST_PLUGINS0.10_NAME=	png
GST_PLUGINS0.10_DIRS=	ext/libpng
GST_PLUGINS0.10_FLAGS=	libpng

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
