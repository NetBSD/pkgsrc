# $NetBSD: Makefile,v 1.10 2012/10/02 21:25:50 asau Exp $

PKGNAME=	${PYPKGPREFIX}-sqlite3-0
PKGREVISION=	3
CATEGORIES=	databases python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Built-in sqlite support for Python 2.5 and up

USE_TOOLS+=		patch

EXTRACT_ELEMENTS=	${PYSUBDIR}/Modules/_sqlite

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_ACCEPTED=	31 27 26 25
PY_SETUP_SUBST+= 	SQLITE_PREFIX=${BUILDLINK_PREFIX.sqlite3}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

# ignore errors due to missing files (EXTRACT_ELEMENTS!)
do-patch:
	set -e;								\
	cd ${WRKSRC};							\
	for f in ${PATCHDIR}/patch-*; do				\
		${PATCH} --batch < "$$f" || ${TRUE};			\
	done

BUILDLINK_API_DEPENDS.python25+=	python25>=2.5.2nb2

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
