# $NetBSD: Makefile,v 1.44 2026/10/11 07:51:10 adam Exp $

DISTNAME=	aubio-0.4.9
PKGREVISION=	21
CATEGORIES=	audio
MASTER_SITES=	https://aubio.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aubio.org/
COMMENT=	Extracting annotations from audio signals
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	txt2man>=0:../../converters/txt2man

USE_TOOLS+=	pkg-config

# avoid loads of html if doxygen is found in host
TOOLS_PATH.doxygen=	false

PKGCONFIG_OVERRIDE+=	aubio.pc.in

WAF_ENV+=	DOXYGEN=none
WAF_ENV+=	SPHINX=none
WAF_ARGS+=	--disable-tests

TOOL_DEPENDS+=	txt2man>=0:../../converters/txt2man

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

PYTHON_FOR_BUILD_ONLY=		tool

.include "options.mk"

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../devel/waf/waf.mk"
.include "../../lang/python/pyversion.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
