# $NetBSD: Makefile,v 1.3 2010/06/13 22:44:34 wiz Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

PKGREVISION=		1

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
