# $NetBSD: Makefile,v 1.3 2006/02/05 23:09:33 joerg Exp $
#

GST_PLUGINS0.8_NAME=	opengl
GST_PLUGINS0.8_DIR=	sys/glsink

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	2

BUILDLINK_DEPENDS.gst-plugins0.8+=	gst-plugins0.8>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
