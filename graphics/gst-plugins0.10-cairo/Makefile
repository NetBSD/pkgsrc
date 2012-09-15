# $NetBSD: Makefile,v 1.16 2012/09/15 10:04:56 obache Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
