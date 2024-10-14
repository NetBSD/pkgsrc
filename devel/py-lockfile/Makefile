# $NetBSD: Makefile,v 1.11 2024/10/14 06:45:39 wiz Exp $

DISTNAME=	lockfile-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lockfile/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/smontanaro/pylockfile/
COMMENT=	Platform-independent file locking module
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=1.8:../../devel/py-pbr

USE_LANGUAGES=	# none

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
