# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:22 joerg Exp $
#

GST_PLUGINS0.8_NAME=	png
GST_PLUGINS0.8_DIR=	ext/libpng
GST_PLUGINS0.8_FLAG=	pngenc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	6

BUILDLINK_API_DEPENDS.png+=	png>=1.2.5nb3	# requires libpng12.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
