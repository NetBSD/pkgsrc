# $NetBSD: Makefile,v 1.2 2005/12/31 12:32:43 wiz Exp $
#

GST_PLUGINS_NAME=	xvid
GST_PLUGINS_DIR=	ext/xvid

BUILDLINK_DEPENDS.xvidcore+=	xvidcore>=1.0.3nb1

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

.include "../../multimedia/xvidcore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
