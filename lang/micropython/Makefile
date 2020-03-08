# $NetBSD: Makefile,v 1.8 2020/03/08 16:42:28 bsiegert Exp $

DISTNAME=	micropython-1.9.2
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://micropython.org/resources/source/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://micropython.org/
COMMENT=	Embedded version of python 3
LICENSE=	mit

DIST_SUBDIR=	${PKGNAME_NOREV}
BUILD_DIRS=	unix

USE_TOOLS+=	pax gmake pkg-config

AUTO_MKDIRS=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		yes

MAKE_ENV+=	PYTHON=${PYTHONBIN:Q}
MAKE_ENV+=	MICROPY_CPYTHON3=${PYTHONBIN:Q}

REPLACE_PYTHON+=	tools/make-frozen.py
REPLACE_PYTHON+=	tests/run-tests

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		unix/main.c
SUBST_SED.fix-paths=		-e 's,%PREFIX%,${PREFIX},g'

pre-configure:
	cd ${WRKSRC}/lib/axtls && ${GMAKE} clean

pre-build:
	cd ${WRKSRC}/unix && ${GMAKE} axtls

do-test:
	cd ${WRKSRC}/unix && env ${MAKE_ENV} ${GMAKE} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/micropython ${DESTDIR}${PREFIX}/bin

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
