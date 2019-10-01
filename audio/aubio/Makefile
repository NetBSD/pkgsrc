# $NetBSD: Makefile,v 1.18 2019/10/01 21:48:26 nia Exp $

DISTNAME=	aubio-0.4.9
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://aubio.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://aubio.org/
COMMENT=	Extracting annotations from audio signals
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	aubio.pc.in

MAKE_FLAGS+=	WAFCMD="${PYTHONBIN} ./waf"
MAKE_FLAGS+=	WAFOPTS="--disable-tests"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"

TOOL_DEPENDS+=	txt2man-[0-9]*:../../converters/txt2man

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

#REPLACE_PYTHON+=	tests/create_tests_source.py

PYTHON_FOR_BUILD_ONLY=	yes

do-configure:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} configure ${MAKE_FLAGS}

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man ${DESTDIR}${PREFIX}/${PKGMANDIR} || ${TRUE}

.include "options.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
