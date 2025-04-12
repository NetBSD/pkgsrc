# $NetBSD: Makefile,v 1.35 2025/04/12 17:54:10 pgoyette Exp $

DISTNAME=	zstandard-0.23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

USE_TOOLS+=	cpp

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

# TODO: switch to this again
# after https://github.com/indygreg/python-zstandard/issues/252
# is fixed
# or not:
# https://github.com/indygreg/python-zstandard/blob/0063333790a853360c816101511635865405834f/c-ext/backend_c.c#L137-L151
#BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.5.6
#.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
