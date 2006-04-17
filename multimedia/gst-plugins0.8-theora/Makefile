# $NetBSD: Makefile,v 1.6 2006/04/17 14:52:11 wiz Exp $
#

GST_PLUGINS0.8_NAME=	theora
GST_PLUGINS0.8_DIR=	ext/theora

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

DEPENDS+=		gst-plugins0.8-ogg>=0.8.1:../../multimedia/gst-plugins0.8-ogg

.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
