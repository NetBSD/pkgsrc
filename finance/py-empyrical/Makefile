# $NetBSD: Makefile,v 1.13 2024/10/17 08:10:49 wiz Exp $

DISTNAME=	empyrical-0.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/empyrical/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/empyrical
COMMENT=	Common financial risk and performance metrics
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bottleneck>=1.0.0:../../math/py-bottleneck
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.2:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.16.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pandas-datareader>=0.2:../../math/py-pandas-datareader
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
