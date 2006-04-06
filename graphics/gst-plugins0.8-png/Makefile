# $NetBSD: Makefile,v 1.6 2006/04/06 06:22:03 reed Exp $
#

GST_PLUGINS0.8_NAME=	png
GST_PLUGINS0.8_DIR=	ext/libpng
GST_PLUGINS0.8_FLAG=	pngenc

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	4

BUILDLINK_API_DEPENDS.png+=	png>=1.2.5nb3	# requires libpng12.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
