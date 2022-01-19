# $NetBSD: Makefile,v 1.22 2022/01/19 06:04:35 adam Exp $

DISTNAME=	zstandard-0.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

PYSETUPBUILDARGS+=	--system-zstd

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.5.1
.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
