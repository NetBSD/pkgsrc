# $NetBSD: Makefile,v 1.1.1.1 2005/10/21 07:42:39 xtraeme Exp $
#

GST_PLUGINS_NAME=	xvid
GST_PLUGINS_DIR=	ext/xvid

BUILDLINK_DEPENDS.xvidcore+=	xvidcore>=1.0.3nb1

.include "../../multimedia/gst-plugins/Makefile.common"

.include "../../multimedia/xvidcore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
