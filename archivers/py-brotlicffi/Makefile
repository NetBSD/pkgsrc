# $NetBSD: Makefile,v 1.6 2026/08/23 07:52:58 wiz Exp $

DISTNAME=	brotlicffi-1.2.0.2
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

# tests need libbrotli sources in ${WRKSRC}/libbrotli

.include "../../archivers/brotli/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
