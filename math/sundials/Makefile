# $NetBSD: Makefile,v 1.9 2026/02/10 08:12:00 wiz Exp $

DISTNAME=	sundials-4.1.0
PKGREVISION=	2
CATEGORIES=	math
#MASTER_SITES=	https://computation.llnl.gov/projects/sundials/download/

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	https://computation.llnl.gov/projects/sundials
COMMENT=	Suite of nonlinear and differential/algrbraic equation solvers
LICENSE=	modified-bsd

PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_CONFIGURE_ARGS+=	-DEXAMPLES_INSTALL_PATH=${PREFIX}/share/examples/sundials

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

post-install:
	${MV} ${DESTDIR}${PREFIX}/include/sundials/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/*/* \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
