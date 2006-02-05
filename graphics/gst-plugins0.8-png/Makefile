# $NetBSD: Makefile,v 1.3 2006/02/05 23:09:33 joerg Exp $
#

GST_PLUGINS0.8_NAME=	png
GST_PLUGINS0.8_DIR=	ext/libpng
GST_PLUGINS0.8_FLAG=	pngenc

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	2

BUILDLINK_DEPENDS.png+=	png>=1.2.5nb3	# requires libpng12.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
