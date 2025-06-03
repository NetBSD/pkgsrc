# $NetBSD: Makefile,v 1.9 2025/06/03 17:59:08 adam Exp $

DISTNAME=	owslib-0.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography www python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OWSLib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://owslib.readthedocs.io/
COMMENT=	OGC Web Service utility library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
