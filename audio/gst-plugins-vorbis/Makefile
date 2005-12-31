# $NetBSD: Makefile,v 1.3 2005/12/31 12:32:31 wiz Exp $
#

GST_PLUGINS_NAME=	vorbis
GST_PLUGINS_DIR=	ext/vorbis

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

DEPENDS+=		gst-plugins-ogg>=0.8.0:../../multimedia/gst-plugins-ogg

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
