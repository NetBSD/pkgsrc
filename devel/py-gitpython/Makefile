# $NetBSD: Makefile,v 1.23 2024/02/16 20:18:44 adam Exp $

DISTNAME=	GitPython-3.1.42
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitpython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python Git Library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	${PYPKGPREFIX}-gitdb>=4.0.1:../../devel/py-gitdb
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
