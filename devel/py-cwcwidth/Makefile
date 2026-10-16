# $NetBSD: Makefile,v 1.15 2026/10/16 19:43:46 adam Exp $

DISTNAME=	cwcwidth-0.1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cwcwidth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sebastinas/cwcwidth
COMMENT=	Python bindings for wc(s)width
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
