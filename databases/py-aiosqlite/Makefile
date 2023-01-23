# $NetBSD: Makefile,v 1.12 2023/01/23 23:41:20 wiz Exp $

DISTNAME=	aiosqlite-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jreese/aiosqlite
COMMENT=	Async bridge to the standard sqlite3 module
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m aiosqlite.tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
