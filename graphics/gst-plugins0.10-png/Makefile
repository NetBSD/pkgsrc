# $NetBSD: Makefile,v 1.14 2012/06/14 07:44:18 sbd Exp $
#

GST_PLUGINS0.10_NAME=	png
GST_PLUGINS0.10_DIRS=	ext/libpng
GST_PLUGINS0.10_FLAGS=	libpng
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
