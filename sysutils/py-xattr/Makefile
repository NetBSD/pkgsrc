# $NetBSD: Makefile,v 1.32 2026/10/26 06:51:12 wiz Exp $

DISTNAME=	xattr-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xattr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.16.0:../../devel/py-cffi

PY_RENAME_BINARIES=	xattr

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
