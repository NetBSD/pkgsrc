# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:28 joerg Exp $
#

GST_PLUGINS0.8_NAME=	theora
GST_PLUGINS0.8_DIR=	ext/theora

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

DEPENDS+=		gst-plugins0.8-ogg>=0.8.1:../../multimedia/gst-plugins0.8-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
