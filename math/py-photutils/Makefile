# $NetBSD: Makefile,v 1.12 2024/10/14 06:45:50 wiz Exp $

DISTNAME=	photutils-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/photutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://photutils.readthedocs.io/en/stable/
COMMENT=	Astropy coordinated module for astronomical photometry
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-scikit-image>=0.14.2:../../math/py-scikit-image
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.19:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=0.1:../../devel/py-extension-helpers
DEPENDS+=	${PYPKGPREFIX}-gwcs>=0.12:../../math/py-gwcs

PYTHON_VERSIONS_INCOMPATIBLE+=	39 # py-scikit-learn py-scikit-image ...

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
