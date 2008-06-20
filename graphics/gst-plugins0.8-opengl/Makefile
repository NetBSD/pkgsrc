# $NetBSD: Makefile,v 1.9 2008/06/20 01:09:22 joerg Exp $
#

GST_PLUGINS0.8_NAME=	opengl
GST_PLUGINS0.8_DIR=	sys/glsink

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=	5

BUILDLINK_API_DEPENDS.gst-plugins0.8+=	gst-plugins0.8>=0.8.7nb1

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
