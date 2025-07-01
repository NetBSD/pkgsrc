# $NetBSD: Makefile,v 1.6 2025/07/01 05:29:29 adam Exp $

DISTNAME=	xarray_einstats-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray-einstats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arviz-devs/xarray-einstats
COMMENT=	Stats, linear algebra and einops for xarray
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.25:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.11:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-xarray>=2023.06.0:../../math/py-xarray

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
