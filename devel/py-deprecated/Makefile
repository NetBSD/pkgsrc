# $NetBSD: Makefile,v 1.6 2025/03/05 09:39:56 wiz Exp $

DISTNAME=	deprecated-1.2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deprecated/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tantale/deprecated
COMMENT=	Python decorator to deprecate old python classes, functions or methods
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.10:../../devel/py-wrapt

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
