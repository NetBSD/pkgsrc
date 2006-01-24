# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:27 wiz Exp $
#

GST_PLUGINS0.8_NAME=	xvid
GST_PLUGINS0.8_DIR=	ext/xvid

BUILDLINK_DEPENDS.xvidcore+=	xvidcore>=1.0.3nb1

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		1

.include "../../multimedia/xvidcore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
