# $NetBSD: Makefile,v 1.5 2025/01/28 09:47:00 adam Exp $

DISTNAME=	OWSLib-0.32.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	geography www python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OWSLib/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://owslib.readthedocs.io/
COMMENT=	OGC Web Service utility library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
