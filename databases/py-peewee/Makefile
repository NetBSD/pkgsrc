# $NetBSD: Makefile,v 1.105 2024/05/29 16:31:52 adam Exp $

DISTNAME=	peewee-3.17.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/peewee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.peewee-orm.com/
COMMENT=	Small, expressive ORM for PostgreSQL, MySQL and SQLite
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

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
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
