# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:26 wiz Exp $

DISTNAME=	pytest_randomly-3.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-randomly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-randomly
COMMENT=	Pytest plugin to randomly order tests and control random.seed
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6.0:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
