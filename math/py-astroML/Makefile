# $NetBSD: Makefile,v 1.9 2024/10/14 06:45:49 wiz Exp $

DISTNAME=	astroML-1.0.2.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astroml.org/
COMMENT=	Astropy affiliated module for machine learning and data mining
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-astropy>=3.0:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.13:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.18:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy-header-[0-9]*:../../devel/py-test-astropy-header
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus-[0-9]*:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-remotedata-[0-9]*:../../net/py-test-remotedata

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
