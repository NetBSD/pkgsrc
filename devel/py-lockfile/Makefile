# $NetBSD: Makefile,v 1.8 2023/06/06 12:41:14 riastradh Exp $

DISTNAME=	lockfile-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lockfile/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/smontanaro/pylockfile/
COMMENT=	Platform-independent file locking module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=1.8:../../devel/py-pbr

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=   27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
