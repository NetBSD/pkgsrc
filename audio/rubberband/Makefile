# $NetBSD: Makefile,v 1.9 2022/04/14 06:34:52 nia Exp $

DISTNAME=	rubberband-1.9.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://breakfastquay.com/files/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://breakfastquay.com/rubberband/
COMMENT=	Audio time-stretching and pitch-shifting library
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

MESON_ARGS+=	-Dfft=fftw
MESON_ARGS+=	-Dresampler=libsamplerate

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/vamp/vamp-plugin.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/ladspa/ladspa-plugin.map

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/rubberband.pc

.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
