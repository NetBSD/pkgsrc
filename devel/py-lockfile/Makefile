# $NetBSD: Makefile,v 1.4 2015/10/17 11:09:58 adam Exp $

DISTNAME=	lockfile-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lockfile/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/smontanaro/pylockfile/
COMMENT=	Platform-independent file locking module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-pbr>=0.6:../../devel/py-pbr

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
