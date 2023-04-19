# $NetBSD: Makefile,v 1.24 2023/04/19 08:10:57 adam Exp $

GST_PLUGINS0.10_NAME=	x264
GST_PLUGINS0.10_DIRS=	ext/x264
PKGREVISION=		13

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

# need shared lib
BUILDLINK_API_DEPENDS.x264+=	x264>=20220601
.include "../../multimedia/x264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
