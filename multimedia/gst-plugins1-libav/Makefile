# $NetBSD: Makefile,v 1.71 2024/10/15 09:17:18 prlw1 Exp $

.include "../../multimedia/gstreamer1/version.mk"

DISTNAME=	gst-libav-${GST_VERSION}
PKGNAME=	${DISTNAME:S/gst/gst-plugins1/}
PKGVERSION=	1
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
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
