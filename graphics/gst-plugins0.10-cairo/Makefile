# $NetBSD: Makefile,v 1.15 2012/06/14 07:44:18 sbd Exp $
#

GST_PLUGINS0.10_NAME=	cairo
GST_PLUGINS0.10_DIRS=	ext/cairo
GST_PLUGINS0.10_FLAGS=	cairo
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"
PKGREVISION=1

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
