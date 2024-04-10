# $NetBSD: Makefile,v 1.15 2024/04/10 16:26:24 adam Exp $

DISTNAME=	execnet-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/execnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://execnet.readthedocs.io/
COMMENT=	Rapid multi-Python deployment
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
