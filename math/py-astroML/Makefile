# $NetBSD: Makefile,v 1.11 2025/03/05 10:12:30 wiz Exp $

DISTNAME=	astroML-1.0.2.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astroML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astroml.org/
COMMENT=	Astropy affiliated module for machine learning and data mining
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-astropy>=3.0:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1.1:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.13:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.18:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy-header-[0-9]*:../../devel/py-test-astropy-header
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus-[0-9]*:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-remotedata-[0-9]*:../../net/py-test-remotedata

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
