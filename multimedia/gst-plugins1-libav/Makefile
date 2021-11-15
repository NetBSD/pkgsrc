# $NetBSD: Makefile,v 1.56 2021/11/15 22:01:20 wiz Exp $

DISTNAME=	gst-libav-1.18.5
PKGNAME=	${DISTNAME:S/gst/gst-plugins1/}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-libav/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/src/gst-libav/
COMMENT=	GStreamer libav/ffmpeg plugin
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config perl

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
