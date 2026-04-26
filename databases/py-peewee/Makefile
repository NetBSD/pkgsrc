# $NetBSD: Makefile,v 1.132 2026/04/26 08:21:20 adam Exp $

DISTNAME=	peewee-4.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/peewee/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.peewee-orm.com/
COMMENT=	Small, expressive ORM for PostgreSQL, MySQL and SQLite
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

MAKE_FLAGS+=	SPHINXBUILD=sphinx-build-${PYVERSSUFFIX}

FILES_SUBST+=	PKGMANDIR=${PKGMANDIR}
MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

REPLACE_PYTHON+=	pwiz.py
PY_RENAME_BINARIES=	pwiz

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-build:
	cd ${WRKSRC}/docs && ${BUILD_MAKE_CMD} man

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/_build/man/peewee.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/peewee-${PYVERSSUFFIX}.1

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
