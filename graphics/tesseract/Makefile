# $NetBSD: Makefile,v 1.22 2016/12/04 05:17:30 ryoon Exp $

DISTNAME=	tesseract-3.04.01
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=tesseract-ocr/}
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/tesseract-ocr/tesseract/
COMMENT=	Tesseract Open Source OCR Engine
LICENSE=	apache-2.0

LANGVER=				3.04.00
DISTFILES+=				tessdata-${LANGVER}${EXTRACT_SUFX}
SITES.tessdata-${LANGVER}.tar.gz=	-${MASTER_SITES:Q}tessdata/archive/${LANGVER}.tar.gz

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pax pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIBLEPT_HEADERSDIR=${BUILDLINK_PREFIX.leptonica}/include

INSTALL_TARGET=		install training-install

INSTALLATION_DIRS=	libexec share/doc/tesseract share/tesseract

post-extract:
	${MV} ${WRKDIR}/tessdata-${LANGVER}/* ${WRKSRC}/tessdata

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
