# $NetBSD: Makefile,v 1.3 2011/04/24 15:31:09 obache Exp $
#

GST_PLUGINS0.10_NAME=	theora
GST_PLUGINS0.10_DIRS=	ext/theora
GST_PLUGINS0.10_FLAGS=	theora

PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
