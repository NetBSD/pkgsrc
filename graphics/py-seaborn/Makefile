# $NetBSD: Makefile,v 1.18 2024/01/28 20:52:26 adam Exp $

DISTNAME=	seaborn-0.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/seaborn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://seaborn.pydata.org/
COMMENT=	Statistical data visualization
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.6.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.25:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.2:../../math/py-pandas
# stats
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.7:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.12:../../math/py-statsmodels
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
