# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 09:42:41 jmmv Exp $
#

GST_PLUGINS_NAME=	vorbis
GST_PLUGINS_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins/Makefile.common"

DEPENDS+=		gst-plugins-ogg>=0.8.0:../../audio/gst-plugins-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
