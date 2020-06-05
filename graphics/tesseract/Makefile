# $NetBSD: Makefile,v 1.54 2020/06/05 12:49:00 jperkin Exp $

DISTNAME=	tesseract-4.1.1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=tesseract-ocr/}
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tesseract-ocr/tesseract
COMMENT=	Open Source OCR Engine
LICENSE=	apache-2.0

LANGVER=	4.0.0
DISTFILES+=	tessdata-${LANGVER}${EXTRACT_SUFX}
SITES.tessdata-${LANGVER}.tar.gz=	-${MASTER_SITES:Q}tessdata/archive/${LANGVER}.tar.gz

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake bash gmake pax pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBLEPT_HEADERSDIR=${BUILDLINK_PREFIX.leptonica}/include

INSTALL_TARGET=		install training-install
REPLACE_BASH+=		${WRKSRC}/src/training/*.sh

post-extract:
	${MV} ${WRKDIR}/tessdata-${LANGVER}/* ${WRKSRC}/tessdata

# For some reason this release tarball lacks these
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh

# Building the training tools requires that the base build is done
post-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} training

post-install:
	cd ${WRKSRC}/tessdata && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install-langs

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/leptonica/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
