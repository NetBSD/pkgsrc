# $NetBSD: Makefile,v 1.9 2024/08/10 15:18:01 wiz Exp $

DISTNAME=	pytest-pylint-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carsongee/pytest-pylint
COMMENT=	Pytest plugin to check source code with Pylint
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.15.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 0.21.0
# 33 passed, 36 warnings

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
