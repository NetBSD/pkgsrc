# $NetBSD: Makefile,v 1.2 2005/12/31 12:32:37 wiz Exp $
#

GST_PLUGINS_NAME=	opengl
GST_PLUGINS_DIR=	sys/glsink

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

BUILDLINK_DEPENDS.gst-plugins+=	gst-plugins>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
