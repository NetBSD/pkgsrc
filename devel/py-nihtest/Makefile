# $NetBSD: Makefile,v 1.26 2026/05/18 16:34:22 wiz Exp $

DISTNAME=	nihtest-1.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nihtest/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/nih-at/nihtest
COMMENT=	Testing tool for command line utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	cmake:test

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

PY_RENAME_BINARIES=	nihtest

post-install:
.for man in nihtest
	${INSTALL_DATA} ${WRKSRC}/manpages/${man}.mdoc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${man}-${PYVERSSUFFIX}.1
.endfor
.for man in nihtest-case nihtest.conf
	${INSTALL_DATA} ${WRKSRC}/manpages/${man}.mdoc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/${man}-${PYVERSSUFFIX}.5
.endfor

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/tests
do-test:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && cmake .. && ${MAKE} && ${SETENV} ${TEST_ENV} ctest -j ${_MAKE_JOBS_N:U1}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
