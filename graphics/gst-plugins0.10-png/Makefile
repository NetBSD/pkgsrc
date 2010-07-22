# $NetBSD: Makefile,v 1.6 2010/07/22 13:22:02 drochner Exp $
#

GST_PLUGINS0.10_NAME=	png
GST_PLUGINS0.10_DIRS=	ext/libpng
GST_PLUGINS0.10_FLAGS=	libpng

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
