# $NetBSD: Makefile,v 1.81 2022/01/04 20:52:43 wiz Exp $

DISTNAME=	peewee-3.14.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/peewee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.peewee-orm.com/
COMMENT=	Small, expressive ORM for PostgreSQL, MySQL and SQLite
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONS_INCOMPATIBLE=	27 # needs features from newer sphinx than python 2.7 supports

MAKE_FLAGS+=	SPHINXBUILD=sphinx-build-${PYVERSSUFFIX}

FILES_SUBST+=	PKGMANDIR=${PKGMANDIR}
MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

REPLACE_PYTHON+=	pwiz.py

SUBST_CLASSES+=		lpath
SUBST_STAGE.lpath=	pre-configure
SUBST_FILES.lpath=	setup.py
SUBST_VARS.lpath=	BUILDLINK_PREFIX.sqlite3

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

# Let Cython re-generate these files. Fixes build with Python 3.9.
pre-configure:
	${RM} ${WRKSRC}/playhouse/_sqlite_ext.c ${WRKSRC}/playhouse/_sqlite_udf.c

post-build:
	cd ${WRKSRC}/docs && ${BUILD_MAKE_CMD} man

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pwiz.py pwiz-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/peewee.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/peewee-${PYVERSSUFFIX}.1

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
