# $NetBSD: Makefile,v 1.4 2023/02/21 17:27:17 adam Exp $

DISTNAME=	lmdb-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmdb/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/jnwatson/py-lmdb
COMMENT=	Universal Python binding for the LMDB
LICENSE=	modified-bsd

.include "../../databases/lmdb/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
