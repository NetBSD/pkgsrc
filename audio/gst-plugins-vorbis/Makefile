# $NetBSD: Makefile,v 1.2 2004/04/16 13:30:49 jmmv Exp $
#

GST_PLUGINS_NAME=	vorbis
GST_PLUGINS_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins/Makefile.common"

DEPENDS+=		gst-plugins-ogg>=0.8.0:../../multimedia/gst-plugins-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
