# $NetBSD: Makefile,v 1.5 2012/02/06 12:41:04 wiz Exp $
#

GST_PLUGINS0.10_NAME=	xvid
GST_PLUGINS0.10_DIRS=	ext/xvid

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

PKGREVISION=		1

.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
