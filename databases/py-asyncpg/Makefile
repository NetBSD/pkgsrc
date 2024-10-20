# $NetBSD: Makefile,v 1.28 2024/10/20 20:12:01 adam Exp $

DISTNAME=	asyncpg-0.30.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/asyncpg
COMMENT=	Asyncio PosgtreSQL driver
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=6.1:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.15.3:../../devel/py-uvloop

# Testing requires postgresql-contrib

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.3:../../devel/py-async-timeout
.endif

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
