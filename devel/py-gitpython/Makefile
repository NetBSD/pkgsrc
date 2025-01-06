# $NetBSD: Makefile,v 1.26 2025/01/06 08:32:21 adam Exp $

DISTNAME=	gitpython-3.1.44
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitpython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gitpython-developers/GitPython
COMMENT=	Python Git Library
LICENSE=	modified-bsd

WHEEL_NAME=	${DISTNAME:S/gitp/GitP/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	${PYPKGPREFIX}-gitdb>=4.0.1:../../devel/py-gitdb
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
