# $NetBSD: Makefile,v 1.2 2005/12/31 12:32:37 wiz Exp $
#

GST_PLUGINS_NAME=	png
GST_PLUGINS_DIR=	ext/libpng
GST_PLUGINS_FLAG=	pngenc

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

BUILDLINK_DEPENDS.png+=	png>=1.2.5nb3	# requires libpng12.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
