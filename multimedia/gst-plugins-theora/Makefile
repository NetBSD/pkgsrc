# $NetBSD: Makefile,v 1.3 2004/09/01 17:01:31 jmmv Exp $
#

GST_PLUGINS_NAME=	theora
GST_PLUGINS_DIR=	ext/theora

.include "../../multimedia/gst-plugins/Makefile.common"

DEPENDS+=		gst-plugins-ogg>=0.8.1:../../multimedia/gst-plugins-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
