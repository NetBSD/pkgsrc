# $NetBSD: Makefile,v 1.19 2024/06/07 12:21:36 wiz Exp $

DISTNAME=	nihtest-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nihtest/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/nih-at/nihtest
COMMENT=	Testing tool for command line utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

USE_TOOLS+=	cmake:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} nihtest nihtest-${PYVERSSUFFIX} || ${TRUE}
.for man in nihtest
	${INSTALL_DATA} ${WRKSRC}/manpages/${man}.mdoc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${man}-${PYVERSSUFFIX}.1
.endfor
.for man in nihtest-case nihtest.conf
	${INSTALL_DATA} ${WRKSRC}/manpages/${man}.mdoc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/${man}-${PYVERSSUFFIX}.5
.endfor

# as of 1.5.1
# 91% tests passed, 5 tests failed out of 54
do-test:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && cmake .. && ${MAKE} && ctest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
