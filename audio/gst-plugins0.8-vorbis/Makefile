# $NetBSD: Makefile,v 1.4 2006/03/06 00:18:14 wiz Exp $
#

GST_PLUGINS0.8_NAME=	vorbis
GST_PLUGINS0.8_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		3

DEPENDS+=		gst-plugins0.8-ogg>=0.8.0:../../multimedia/gst-plugins0.8-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
