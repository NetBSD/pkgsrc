# $NetBSD: Makefile,v 1.6 2026/08/17 20:23:06 js Exp $

# There are no release tags for glasgow
DISTNAME=	glasgow-0.0.20260817
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GlasgowEmbedded/}
GITHUB_TAG=	889097096b450cb880eaf1a1f0d0518fe6566523

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://glasgow-embedded.org/
COMMENT=	Software for the Glasgow Interface Explorer
LICENSE=	0-clause-bsd OR apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.8<5:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-amaranth>=0.5.9<0.6:../../devel/py-amaranth
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=3.0.0<5:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-fx2>=0.16<1:../../devel/py-fx2
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.67.3:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-pyvcd>=0.4.1<0.5:../../devel/py-pyvcd
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.6<0.5:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-importlib-resources:../../devel/py-importlib-resources
DEPENDS+=	yosys>=0.31.0.13:../../devel/yosys
DEPENDS+=	nextpnr-ice40>=0.1:../../devel/nextpnr-ice40
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-remotes>=1.2<2:../../www/py-aiohttp-remotes
BUILD_DEPENDS+=	${PYPKGPREFIX}-pdm>=2.3.0<3.0:../../devel/py-pdm

USE_LANGUAGES=	# none

PYSETUPSUBDIR=	software

MAKE_ENV+=	PDM_BUILD_SCM_VERSION=${PKGVERSION_NOREV}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
