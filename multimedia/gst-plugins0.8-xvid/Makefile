# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:28 joerg Exp $
#

GST_PLUGINS0.8_NAME=	xvid
GST_PLUGINS0.8_DIR=	ext/xvid

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.xvidcore+=	xvidcore>=1.0.3nb1

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

.include "../../multimedia/xvidcore/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
