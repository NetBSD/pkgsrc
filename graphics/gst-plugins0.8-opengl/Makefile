# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:15 wiz Exp $
#

GST_PLUGINS0.8_NAME=	opengl
GST_PLUGINS0.8_DIR=	sys/glsink

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	1

BUILDLINK_DEPENDS.gst-plugins0.8+=	gst-plugins0.8>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
