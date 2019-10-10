# $NetBSD: Makefile,v 1.12 2019/10/10 07:58:41 adam Exp $

DISTNAME=	asyncpg-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/asyncpg
COMMENT=	Asyncio PosgtreSQL driver
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.5.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.8.0:../../devel/py-uvloop

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Testing requires postgresql-contrib

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
