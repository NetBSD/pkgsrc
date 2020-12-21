# $NetBSD: Makefile,v 1.2 2020/12/21 09:02:04 mef Exp $

DISTNAME=	pyvo-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyvo.readthedocs.io/en/latest/
COMMENT=	Astropy affiliated Python module for accessing virtual observatories
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-astropy>=4.2:../../math/py-astropy
DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
