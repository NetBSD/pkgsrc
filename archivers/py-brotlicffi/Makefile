# $NetBSD: Makefile,v 1.5 2026/03/07 11:46:10 adam Exp $

DISTNAME=	brotlicffi-1.2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotlicffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/brotlicffi
COMMENT=	Python CFFI bindings to the Brotli library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

MAKE_ENV+=	USE_SHARED_BROTLI=1

.include "../../archivers/brotli/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
