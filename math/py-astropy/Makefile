# $NetBSD: Makefile,v 1.2 2021/12/30 13:05:36 adam Exp $

DISTNAME=	astropy-4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astropy.org/
COMMENT=	Python module for astronomical calculations and data analysis
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	libxml2>=2.9.10:../../textproc/libxml2
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-h5py>=2.9.0:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.9.3:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.0.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-bleach>=3.2.1:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.13:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.14:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.2.2:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-pytz>=2020.4:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-setuptools>=50.3.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mpmath>=1.1.0:../../math/py-mpmath
DEPENDS+=	${PYPKGPREFIX}-bottleneck>=1.3.2:../../math/py-bottleneck
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.7.1:../../math/py-asdf
DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=0.1:../../devel/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-jplephem>=2.15:../../math/py-jplephem
DEPENDS+=	${PYPKGPREFIX}-pyerfa>=1.7.1.1:../../math/py-pyerfa

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
