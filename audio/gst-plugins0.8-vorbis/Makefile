# $NetBSD: Makefile,v 1.5 2006/03/21 06:00:44 jlam Exp $
#

GST_PLUGINS0.8_NAME=	vorbis
GST_PLUGINS0.8_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		4

DEPENDS+=		gst-plugins0.8-ogg>=0.8.0:../../multimedia/gst-plugins0.8-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
