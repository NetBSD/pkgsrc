# $NetBSD: Makefile,v 1.23 2022/11/23 16:20:45 adam Exp $

GST_PLUGINS0.10_NAME=	x264
GST_PLUGINS0.10_DIRS=	ext/x264
PKGREVISION=		12

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

# need shared lib
BUILDLINK_API_DEPENDS.x264+=	x264>=20220601
.include "../../multimedia/x264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
