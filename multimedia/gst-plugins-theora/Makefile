# $NetBSD: Makefile,v 1.4 2005/12/31 12:32:43 wiz Exp $
#

GST_PLUGINS_NAME=	theora
GST_PLUGINS_DIR=	ext/theora

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

DEPENDS+=		gst-plugins-ogg>=0.8.1:../../multimedia/gst-plugins-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
