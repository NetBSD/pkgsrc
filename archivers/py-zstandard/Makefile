# $NetBSD: Makefile,v 1.10 2019/05/02 10:10:56 wiz Exp $

DISTNAME=	zstandard-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

PYSETUPBUILDARGS+=	--system-zstd

BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.4.0
.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
