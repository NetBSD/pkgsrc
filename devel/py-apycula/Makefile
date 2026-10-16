# $NetBSD: Makefile,v 1.7 2026/10/16 19:43:45 adam Exp $

DISTNAME=	apycula-0.34
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apycula/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/apicula
COMMENT=	Open Source tools for Gowin FPGAs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-fastcrc>=0:../../misc/py-fastcrc
DEPENDS+=	${PYPKGPREFIX}-msgspec>=0:../../devel/py-msgspec
DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	gowin_pack gowin_pll gowin_unpack

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
