# $NetBSD: Makefile,v 1.34 2026/06/28 15:41:11 wiz Exp $

DISTNAME=	asyncpg-0.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/asyncpg
COMMENT=	Asyncio PosgtreSQL driver
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=6.1:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.15.3:../../devel/py-uvloop

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# Testing requires postgresql-contrib

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.3:../../devel/py-async-timeout
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
