# $NetBSD: Makefile,v 1.37 2024/02/04 01:33:38 ryoon Exp $

DISTNAME=	aubio-0.4.9
PKGREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	https://aubio.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aubio.org/
COMMENT=	Extracting annotations from audio signals
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	txt2man-[0-9]*:../../converters/txt2man

USE_TOOLS+=	pkg-config

# avoid loads of html if doxygen is found in host
TOOLS_PATH.doxygen=	${FALSE}

PKGCONFIG_OVERRIDE+=	aubio.pc.in

WAF_ENV+=	DOXYGEN=none
WAF_ENV+=	SPHINX=none
WAF_ARGS+=	--disable-tests

TOOL_DEPENDS+=	txt2man-[0-9]*:../../converters/txt2man

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

# open() flag 'rUb'
PYTHON_VERSIONS_INCOMPATIBLE+=	311
# No module named 'imp'
# https://github.com/aubio/aubio/issues/394
PYTHON_VERSIONS_INCOMPATIBLE+=	312
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
