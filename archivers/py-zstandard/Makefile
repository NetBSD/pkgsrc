# $NetBSD: Makefile,v 1.36 2025/08/17 20:43:58 wiz Exp $

DISTNAME=	zstandard-0.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_TOOLS+=	cpp

# upstream prefers to use its bundled version of zstd
# https://github.com/indygreg/python-zstandard/blob/0063333790a853360c816101511635865405834f/c-ext/backend_c.c#L137-L151
#BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.5.7
#.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
