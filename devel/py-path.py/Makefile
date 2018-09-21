# $NetBSD: Makefile,v 1.5 2018/09/21 10:52:34 adam Exp $

DISTNAME=	path.py-11.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/path.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/path.py
COMMENT=	Module wrapper for os.path
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_path.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
