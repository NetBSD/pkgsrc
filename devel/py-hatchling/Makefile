# $NetBSD: Makefile,v 1.35 2026/08/11 14:28:17 adam Exp $

DISTNAME=	hatchling-1.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatchling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hatch.pypa.io/
COMMENT=	Modern, extensible Python build backend
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.1:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.11.1:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-trove-classifiers-[0-9]*:../../misc/py-trove-classifiers

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	hatchling

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.2.2:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
