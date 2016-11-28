# $NetBSD: Makefile,v 1.5 2016/11/28 12:45:55 wiz Exp $

DISTNAME=	flake8-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/flake8/
COMMENT=	Modular source code checker for Python programs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flakes>=0.8.1:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe-[0-9]*:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# TEST_DEPENDS
# 8 test failures as of 3.0.4, see
# https://gitlab.com/pycqa/flake8/issues/232
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/flake8 ${DESTDIR}${PREFIX}/bin/flake8-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
