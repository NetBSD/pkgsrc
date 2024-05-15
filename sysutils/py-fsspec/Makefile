# $NetBSD: Makefile,v 1.10 2024/05/15 15:19:03 adam Exp $

DISTNAME=	fsspec-2024.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fsspec/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fsspec/filesystem_spec
COMMENT=	File-system specification
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
