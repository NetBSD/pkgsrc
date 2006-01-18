# $NetBSD: Makefile,v 1.1 2006/01/18 12:44:01 jmmv Exp $
#

GST_PLUGINS0.8_NAME=	vorbis
GST_PLUGINS0.8_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins0.8/Makefile.common"

DEPENDS+=		gst-plugins0.8-ogg>=0.8.0:../../multimedia/gst-plugins0.8-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
