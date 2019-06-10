# $NetBSD: Makefile,v 1.58 2019/06/10 07:36:14 adam Exp $

DISTNAME=	peewee-3.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/peewee/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://www.peewee-orm.com/
COMMENT=	Small, expressive ORM for PostgreSQL, MySQL and SQLite
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

MAKE_FLAGS+=	SPHINXBUILD=sphinx-build${PYVERSSUFFIX}

FILES_SUBST+=	PKGMANDIR=${PKGMANDIR}
MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

REPLACE_PYTHON+=	pwiz.py

SUBST_CLASSES+=		lpath
SUBST_STAGE.lpath=	pre-configure
SUBST_FILES.lpath=	setup.py
SUBST_VARS.lpath=	BUILDLINK_PREFIX.sqlite3

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

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
