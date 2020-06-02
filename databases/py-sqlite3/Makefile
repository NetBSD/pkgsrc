# $NetBSD: Makefile,v 1.38 2020/06/02 08:23:31 adam Exp $

PKGNAME=	${PYPKGPREFIX}-sqlite3-${PY_DISTVERSION}
PKGREVISION=	17
CATEGORIES=	databases python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/
COMMENT=	Built-in sqlite support for Python 2.5 and up

USE_GCC_RUNTIME=	yes

# part of python itself; using distutils.mk will install a useless egg
PYDISTUTILSPKG=		yes
PY_SETUP_SUBST+=	SQLITE_PREFIX=${BUILDLINK_PREFIX.sqlite3}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
