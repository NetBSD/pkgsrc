# $NetBSD: Makefile,v 1.78 2024/05/29 16:33:03 adam Exp $

DISTNAME=	tesseract-5.3.4
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=tesseract-ocr/}
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tesseract-ocr/tesseract
COMMENT=	Open Source OCR Engine
LICENSE=	apache-2.0

LANGVER=	4.1.0
DISTFILES+=	tessdata-${LANGVER}${EXTRACT_SUFX}
SITES.tessdata-${LANGVER}.tar.gz=	-${MASTER_SITES:Q}tessdata_best/archive/${LANGVER}.tar.gz

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TEST_DEPENDS+=	googletest-[0-9]*:../../devel/googletest

USE_CXX_FEATURES+=	filesystem
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake bash gmake pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBLEPT_HEADERSDIR=${BUILDLINK_PREFIX.leptonica}/include
INSTALL_TARGET=		install training-install
TEST_TARGET=		check
REPLACE_BASH+=		src/training/*.sh

#CMAKE_ARGS+=	-DUSE_SYSTEM_ICU=ON

post-extract:
	${MV} ${WRKDIR}/tessdata_best-${LANGVER}/*.traineddata ${WRKSRC}/tessdata/
	${MV} ${WRKDIR}/tessdata_best-${LANGVER}/script ${WRKSRC}/tessdata/

# For some reason this release tarball lacks these
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh
	${MV} ${WRKSRC}/VERSION ${WRKSRC}/VERSION.txt

# Building the training tools requires that the base build is done
post-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} training

post-install:
	cd ${WRKSRC}/tessdata && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install-langs

.include "../../archivers/libarchive/buildlink3.mk"
#.include "../../devel/cmake/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/leptonica/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
