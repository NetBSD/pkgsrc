# $NetBSD: Makefile,v 1.65 2026/08/04 21:44:04 wiz Exp $

DISTNAME=	cffi-2.1.1
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

PY_RENAME_BINARIES=	cffi-gen-src

# as of 2.1.1
# 2 due to -ldl, 6 because of cwrapper
# 8 failed, 1927 passed, 142 skipped, 4 xfailed, 24 warnings

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
