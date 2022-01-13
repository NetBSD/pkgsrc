# $NetBSD: Makefile,v 1.11 2022/01/13 19:31:22 wiz Exp $

DISTNAME=	path.py-11.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/path.py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/path.py
COMMENT=	Module wrapper for os.path
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	packaging:test pygments:test setuptools_scm:build

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test_path.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
