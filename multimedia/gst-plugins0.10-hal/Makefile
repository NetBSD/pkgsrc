# $NetBSD: Makefile,v 1.2 2011/04/22 13:44:15 obache Exp $
#

GST_PLUGINS0.10_NAME=	hal
GST_PLUGINS0.10_DIRS=	ext/hal
GST_PLUGINS0.10_FLAGS=	hal

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
