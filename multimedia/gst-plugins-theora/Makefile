# $NetBSD: Makefile,v 1.2 2004/04/16 13:42:13 jmmv Exp $
#

GST_PLUGINS_NAME=	theora
GST_PLUGINS_DIR=	ext/theora

PKGREVISION=		1

.include "../../multimedia/gst-plugins/Makefile.common"

DEPENDS+=		gst-plugins-ogg>=0.8.1:../../multimedia/gst-plugins-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
