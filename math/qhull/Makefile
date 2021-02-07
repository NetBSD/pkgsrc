# $NetBSD: Makefile,v 1.8 2021/02/07 15:23:47 adam Exp $

DISTNAME=	qhull-2020-src-8.0.2
PKGNAME=	qhull-2020.2
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qhull.org/
COMMENT=	Computing the convex hull

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/${PKGMANDIR}/man1

# Remove non-portable file not used in build or test.
post-extract:
	rm -f ${WRKSRC}/eg/q_benchmark ${WRKSRC}/eg/qhull-zip.sh

.include "../../mk/bsd.pkg.mk"
