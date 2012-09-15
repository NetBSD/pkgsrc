# $NetBSD: Makefile,v 1.8 2012/09/15 10:05:48 obache Exp $
#

GST_PLUGINS0.10_NAME=	hal
GST_PLUGINS0.10_DIRS=	ext/hal
GST_PLUGINS0.10_FLAGS=	hal
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
