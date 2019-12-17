# $NetBSD: Makefile,v 1.13 2019/12/17 10:50:41 leot Exp $

DISTNAME=	zstandard-0.12.0
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

#
# XXX: At the moment py-zstandard only supports zstd<1.4.3, use bundled
# XXX: zstd instead.
#
#PYSETUPBUILDARGS+=	--system-zstd
#
#BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.4.0
#.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
