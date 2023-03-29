# $NetBSD: Makefile,v 1.4 2023/03/29 09:34:04 wiz Exp $

DISTNAME=	brotlipy-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotlipy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/brotlipy/
COMMENT=	Python Bindings to the Brotli Compression Algorithm
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

.include "../../lang/python/egg.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
.endif

.include "../../mk/bsd.pkg.mk"
