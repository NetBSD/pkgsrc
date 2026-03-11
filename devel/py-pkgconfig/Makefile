# $NetBSD: Makefile,v 1.14 2026/03/11 10:36:12 adam Exp $

DISTNAME=	pkgconfig-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkgconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matze/pkgconfig
COMMENT=	Python wrapper for pkg-config
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config:run

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
