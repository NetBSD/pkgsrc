# $NetBSD: Makefile,v 1.48 2023/06/28 14:05:32 riastradh Exp $

PKGNAME=	${PYPKGPREFIX}-sqlite3-${PY_DISTVERSION}
PKGREVISION=	24
CATEGORIES=	databases python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/
COMMENT=	Built-in sqlite support for Python 2.5 and up

USE_GCC_RUNTIME=	yes

# part of python itself; using egg.mk will install a useless egg
PYDISTUTILSPKG=		yes
PY_SETUP_SUBST+=	SQLITE_PREFIX=${BUILDLINK_PREFIX.sqlite3}
PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} >= 310
USE_LANGUAGES+=		c99	# for (const char *pos = ...
.endif

.if ${PYTHON_VERSION} == 311
SUBST_CLASSES+=		py311
SUBST_FILES.py311+=	setup.py
SUBST_SED.py311+=	-e "s+'_sqlite/cache.c',+'_sqlite/blob.c',+"
SUBST_STAGE.py311=	pre-build
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
