# $NetBSD: Makefile,v 1.3 2024/08/16 19:10:37 js Exp $

# There are no release tags for glasgow
GLASGOW_VERSION=	0.0.20240810

DISTNAME=	glasgow-${GLASGOW_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GlasgowEmbedded/}
GITHUB_TAG=	60736dc71c02b9ba042e1f080fd3565c374e8458
CATEGORIES=	devel
PYSETUPSUBDIR=	software

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://glasgow-embedded.org/
COMMENT=	Software for the Glasgow Interface Explorer
LICENSE=	0-clause-bsd OR apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.8<5:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-amaranth>=0.5.1<0.6:../../devel/py-amaranth
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.0.0<5:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-fx2>=0.11<1:../../devel/py-fx2
DEPENDS+=	${PYPKGPREFIX}-pyvcd>=0.2<0.5:../../devel/py-pyvcd
DEPENDS+=	yosys>=0.31.0.13:../../devel/yosys
DEPENDS+=	nextpnr-ice40>=0.1:../../devel/nextpnr-ice40
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-remotes>=1.2<2:../../www/py-aiohttp-remotes
BUILD_DEPENDS+= ${PYPKGPREFIX}-pdm>=2.3.0<3.0:../../devel/py-pdm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

MAKE_ENV+=	PDM_BUILD_SCM_VERSION=${PKGVERSION}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
