# $NetBSD: Makefile,v 1.2 2023/09/27 15:30:38 adam Exp $

DISTNAME=	brotlicffi-1.1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotlicffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/brotlicffi
COMMENT=	Python CFFI bindings to the Brotli library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

MAKE_ENV+=	USE_SHARED_BROTLI=1

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../archivers/brotli/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
