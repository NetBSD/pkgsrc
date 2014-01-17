# $NetBSD: Makefile,v 1.3 2014/01/17 14:45:26 wiz Exp $

DISTNAME=	lockfile-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	#

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/smontanaro/pylockfile/
COMMENT=	Platform-independent file locking module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3

PYDISTUTILSPKG=		yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
