# $NetBSD: Makefile,v 1.6 2012/09/22 12:36:45 obache Exp $
#

GST_PLUGINS0.10_NAME=	theora
GST_PLUGINS0.10_DIRS=	ext/theora
GST_PLUGINS0.10_FLAGS=	theora
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
