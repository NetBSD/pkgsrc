# $NetBSD: Makefile,v 1.5 2006/03/21 06:00:46 jlam Exp $
#

GST_PLUGINS0.8_NAME=	opengl
GST_PLUGINS0.8_DIR=	sys/glsink

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	4

BUILDLINK_DEPENDS.gst-plugins0.8+=	gst-plugins0.8>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
