# $NetBSD: Makefile,v 1.10 2023/11/07 09:22:40 wiz Exp $

DISTNAME=	poetry_core-1.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Poetry PEP 517 build backend
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.10:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=1.0.0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.21:../../devel/py-virtualenv
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

# for tests only
USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
