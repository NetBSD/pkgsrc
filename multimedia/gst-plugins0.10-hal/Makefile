# $NetBSD: Makefile,v 1.7 2012/06/14 07:44:18 sbd Exp $
#

GST_PLUGINS0.10_NAME=	hal
GST_PLUGINS0.10_DIRS=	ext/hal
GST_PLUGINS0.10_FLAGS=	hal
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
