# $NetBSD: Makefile,v 1.17 2012/10/02 17:11:12 tron Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo
PKGREVISION=		3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
