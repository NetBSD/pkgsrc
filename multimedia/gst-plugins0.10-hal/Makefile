# $NetBSD: Makefile,v 1.1.1.1 2008/11/27 17:51:28 jmcneill Exp $
#

GST_PLUGINS0.10_NAME=	hal
GST_PLUGINS0.10_DIRS=	ext/hal
GST_PLUGINS0.10_FLAGS=	hal

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
