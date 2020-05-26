# $NetBSD: Makefile,v 1.2 2020/05/26 12:41:25 adam Exp $

DISTNAME=	aiosqlite-0.13.0
PKGREVISION=	1
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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
