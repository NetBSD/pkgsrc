# $NetBSD: Makefile,v 1.5 2023/06/15 06:13:08 wiz Exp $

DISTNAME=	nihtest-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nihtest/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/nih-at/nihtest
COMMENT=	Testing tool for command line utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} nihtest nihtest-${PYVERSSUFFIX} || ${TRUE}
.for man in nihtest
	${INSTALL_DATA} ${WRKSRC}/manpages/${man}.mdoc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${man}-${PYVERSSUFFIX}.1
.endfor
.for man in nihtest-case nihtest.conf
	${INSTALL_DATA} ${WRKSRC}/manpages/${man}.mdoc ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/${man}-${PYVERSSUFFIX}.5
.endfor

do-test:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}/build && cmake .. && ${MAKE} && ctest

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
