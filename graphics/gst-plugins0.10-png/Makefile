# $NetBSD: Makefile,v 1.3 2009/06/05 10:48:38 drochner Exp $
#

GST_PLUGINS0.10_NAME=	png
GST_PLUGINS0.10_DIRS=	ext/libpng
GST_PLUGINS0.10_FLAGS=	libpng

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=	1

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
