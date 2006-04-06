# $NetBSD: Makefile,v 1.6 2006/04/06 06:22:25 reed Exp $
#

GST_PLUGINS0.8_NAME=	xvid
GST_PLUGINS0.8_DIR=	ext/xvid

BUILDLINK_API_DEPENDS.xvidcore+=	xvidcore>=1.0.3nb1

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		4

.include "../../multimedia/xvidcore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
