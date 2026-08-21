# $NetBSD: Makefile,v 1.12 2026/08/21 16:59:01 adam Exp $

DISTNAME=	appnope-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/appnope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/minrk/appnope
COMMENT=	Disable App Nap on macOS
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	Darwin-*-*

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling

USE_LANGUAGES=	# none

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
