# $NetBSD: Makefile,v 1.6 2006/04/06 06:22:02 reed Exp $
#

GST_PLUGINS0.8_NAME=	opengl
GST_PLUGINS0.8_DIR=	sys/glsink

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	4

BUILDLINK_API_DEPENDS.gst-plugins0.8+=	gst-plugins0.8>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
