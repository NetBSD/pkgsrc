# $NetBSD: Makefile,v 1.8 2026/02/24 10:06:44 adam Exp $

DISTNAME=	xarray_einstats-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray-einstats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arviz-devs/xarray-einstats
COMMENT=	Stats, linear algebra and einops for xarray
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-numpy>=2.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.13:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-xarray>=2024.02.0:../../math/py-xarray

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
