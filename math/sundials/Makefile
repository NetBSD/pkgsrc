# $NetBSD: Makefile,v 1.1 2018/07/07 04:15:18 minskim Exp $

DISTNAME=	sundials-3.1.1
CATEGORIES=	math
MASTER_SITES=	https://computation.llnl.gov/projects/sundials/download/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://computation.llnl.gov/projects/sundials
COMMENT=	Suite of nonlinear and differential/algrbraic equation solvers
LICENSE=	modified-bsd

USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/build

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DEXAMPLES_INSTALL_PATH=${PREFIX}/share/examples/sundials

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-extract:
	${MKDIR} ${WRKSRC}

post-install:
	${MV} ${DESTDIR}${PREFIX}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/../README.md ${WRKSRC}/../doc/*/* \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
