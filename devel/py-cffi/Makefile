# $NetBSD: Makefile,v 1.62 2025/09/21 15:31:05 wiz Exp $

DISTNAME=	cffi-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cffi.readthedocs.io/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

USE_LANGUAGES=	c c++ # c++ for testing only
USE_TOOLS+=	pkg-config

# as of 2.0.0
# 8 failed, 1914 passed, 131 skipped, 4 xfailed, 19 warnings

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
