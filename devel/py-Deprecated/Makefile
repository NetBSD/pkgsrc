# $NetBSD: Makefile,v 1.2 2022/01/04 20:52:46 wiz Exp $

DISTNAME=	Deprecated-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=D/Deprecated/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tantale/deprecated
COMMENT=	@deprecated decorator to deprecate old classes, functions, or methods
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.10:../../devel/py-wrapt

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
