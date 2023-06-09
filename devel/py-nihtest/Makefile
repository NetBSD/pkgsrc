# $NetBSD: Makefile,v 1.2 2023/06/09 21:06:04 wiz Exp $

DISTNAME=	nihtest-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nihtest/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/nih-at/nihtest
COMMENT=	Testing tool for command line utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} nihtest nihtest-${PYVERSSUFFIX} || ${TRUE}

do-test:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && cmake .. && ${MAKE} && ctest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
