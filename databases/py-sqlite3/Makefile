# $NetBSD: Makefile,v 1.20 2014/03/13 11:08:50 jperkin Exp $

PKGNAME=	${PYPKGPREFIX}-sqlite3-${PY_DISTVERSION}
PKGREVISION=	2
CATEGORIES=	databases python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Built-in sqlite support for Python 2.5 and up

USE_GCC_RUNTIME=	yes
USE_TOOLS+=		patch

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_sqlite

# part of python itself; using distutils.mk will install a useless egg
PYDISTUTILSPKG=		yes
PY_SETUP_SUBST+= 	SQLITE_PREFIX=${BUILDLINK_PREFIX.sqlite3}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	set -e;								\
	cd ${WRKSRC};							\
	for f in ${PATCHDIR}/patch-*; do				\
		${PATCH} --batch < "$$f" || ${TRUE};			\
	done

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
