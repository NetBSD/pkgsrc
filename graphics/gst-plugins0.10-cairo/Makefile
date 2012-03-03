# $NetBSD: Makefile,v 1.14 2012/03/03 00:14:25 wiz Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
