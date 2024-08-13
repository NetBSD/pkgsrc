# $NetBSD: Makefile,v 1.2 2024/08/13 19:47:30 wiz Exp $

DISTNAME=	amaranth-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/amaranth/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://pypi.org/project/amaranth/
COMMENT=	Toolchain for developing hardware based on synchronous digital logic
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-jschon>=0.11<0.12:../../textproc/py-jschon
DEPENDS+=	${PYPKGPREFIX}-pyvcd>=0.2<0.5:../../devel/py-pyvcd
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
BUILD_DEPENDS+=	${PYPKGPREFIX}-pdm>=2.3.0<3.0:../../devel/py-pdm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
