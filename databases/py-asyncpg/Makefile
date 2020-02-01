# $NetBSD: Makefile,v 1.14 2020/02/01 20:36:47 adam Exp $

DISTNAME=	asyncpg-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/asyncpg
COMMENT=	Asyncio PosgtreSQL driver
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.7.9:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.14.0:../../devel/py-uvloop

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Testing requires postgresql-contrib

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
