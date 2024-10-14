# $NetBSD: Makefile,v 1.2 2024/10/14 06:45:53 wiz Exp $

DISTNAME=	xarray_einstats-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray-einstats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/arviz-devs/xarray-einstats
COMMENT=	Stats, linear algebra and einops for xarray
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.22:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.8:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-xarray>=2022.09.0:../../math/py-xarray

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
