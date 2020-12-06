# $NetBSD: Makefile,v 1.17 2020/12/06 10:55:42 adam Exp $

DISTNAME=	zstandard-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi

PYTHON_VERSIONED_DEPENDENCIES=	hypothesis:test

PYSETUPBUILDARGS+=	--system-zstd

BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.4.5
.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
