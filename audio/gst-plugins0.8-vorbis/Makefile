# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:06 joerg Exp $
#

GST_PLUGINS0.8_NAME=	vorbis
GST_PLUGINS0.8_DIR=	ext/vorbis

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

DEPENDS+=		gst-plugins0.8-ogg>=0.8.0:../../multimedia/gst-plugins0.8-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
