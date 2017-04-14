# $NetBSD: Makefile,v 1.1 2017/04/14 12:10:26 leot Exp $

DISTNAME=	brotlipy-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotlipy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/brotlipy/
COMMENT=	Python Bindings to the Brotli Compression Algorithm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

.include "../../lang/python/egg.mk"

.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
.endif

.include "../../mk/bsd.pkg.mk"
