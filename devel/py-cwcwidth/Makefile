# $NetBSD: Makefile,v 1.14 2026/06/28 15:41:14 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
