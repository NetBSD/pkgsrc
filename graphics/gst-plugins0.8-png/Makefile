# $NetBSD: Makefile,v 1.7 2006/04/17 13:46:32 wiz Exp $
#

GST_PLUGINS0.8_NAME=	png
GST_PLUGINS0.8_DIR=	ext/libpng
GST_PLUGINS0.8_FLAG=	pngenc

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	6

BUILDLINK_API_DEPENDS.png+=	png>=1.2.5nb3	# requires libpng12.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
