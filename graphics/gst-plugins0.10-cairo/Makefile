# $NetBSD: Makefile,v 1.13 2012/02/28 18:43:42 drochner Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
