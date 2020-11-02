# $NetBSD: Makefile,v 1.6 2020/11/02 10:16:13 adam Exp $

DISTNAME=	aiosqlite-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiosqlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jreese/aiosqlite
COMMENT=	Async bridge to the standard sqlite3 module
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-aiounittest-[0-9]*:../../devel/py-aiounittest

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m aiosqlite.tests

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
