# $NetBSD: Makefile,v 1.6 2012/03/03 00:13:39 wiz Exp $
#

GST_PLUGINS0.10_NAME=	hal
GST_PLUGINS0.10_DIRS=	ext/hal
GST_PLUGINS0.10_FLAGS=	hal

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
