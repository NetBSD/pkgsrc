# $NetBSD: Makefile,v 1.27 2024/12/26 23:20:42 adam Exp $

DISTNAME=	xarray-2024.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/xarray
COMMENT=	N-D labeled arrays and datasets in Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.24:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=2.1:../../math/py-pandas

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
