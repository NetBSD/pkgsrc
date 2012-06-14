# $NetBSD: Makefile,v 1.5 2012/06/14 07:45:17 sbd Exp $
#

GST_PLUGINS0.10_NAME=	theora
GST_PLUGINS0.10_DIRS=	ext/theora
GST_PLUGINS0.10_FLAGS=	theora
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
