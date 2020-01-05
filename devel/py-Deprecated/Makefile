# $NetBSD: Makefile,v 1.1 2020/01/05 17:53:53 minskim Exp $

DISTNAME=	Deprecated-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
