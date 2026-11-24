# $NetBSD: Makefile,v 1.10 2026/11/24 08:12:46 adam Exp $

DISTNAME=	deprecated-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deprecated/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tantale/deprecated
COMMENT=	Python decorator to deprecate old python classes, functions or methods
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.16:../../devel/py-wrapt

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
