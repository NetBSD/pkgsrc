# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 09:45:46 jmmv Exp $
#

GST_PLUGINS_NAME=	png
GST_PLUGINS_DIR=	ext/libpng
GST_PLUGINS_FLAG=	pngenc

.include "../../multimedia/gst-plugins/Makefile.common"

BUILDLINK_DEPENDS.png+=	png>=1.2.5nb3	# requires libpng12.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
