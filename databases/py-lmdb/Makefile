# $NetBSD: Makefile,v 1.2 2021/12/27 10:53:17 adam Exp $

DISTNAME=	lmdb-1.2.1
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
