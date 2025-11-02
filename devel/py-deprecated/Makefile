# $NetBSD: Makefile,v 1.8 2025/11/02 20:22:47 adam Exp $

DISTNAME=	deprecated-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deprecated/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tantale/deprecated
COMMENT=	Python decorator to deprecate old python classes, functions or methods
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.10:../../devel/py-wrapt

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
