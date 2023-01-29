# $NetBSD: Makefile,v 1.64 2023/01/29 21:17:18 ryoon Exp $

PKGREVISION= 1
.include "../../multimedia/gstreamer1/version.mk"

DISTNAME=	gst-libav-${GST_VERSION}
PKGNAME=	${DISTNAME:S/gst/gst-plugins1/}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-libav/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://gstreamer.freedesktop.org/src/gst-libav/
COMMENT=	GStreamer libav/ffmpeg plugin

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
