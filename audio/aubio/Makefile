# $NetBSD: Makefile,v 1.28 2023/01/29 21:15:22 ryoon Exp $

DISTNAME=	aubio-0.4.9
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	https://aubio.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://aubio.org/
COMMENT=	Extracting annotations from audio signals
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	aubio.pc.in

WAF_ARGS+=	--disable-tests

TOOL_DEPENDS+=	txt2man-[0-9]*:../../converters/txt2man
BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

PYTHON_FOR_BUILD_ONLY=	tool

.include "options.mk"
.include "../../devel/waf/waf.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
