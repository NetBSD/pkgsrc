# $NetBSD: Makefile,v 1.29 2024/03/20 13:41:17 adam Exp $

DISTNAME=	pytest-asyncio-0.23.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=51.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.36:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.7.1:../../devel/py-hypothesis

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
