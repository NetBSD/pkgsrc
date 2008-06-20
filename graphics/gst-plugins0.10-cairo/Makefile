# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:22 joerg Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
