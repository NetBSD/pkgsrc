# $NetBSD: Makefile,v 1.1 2018/07/04 05:18:06 minskim Exp $

DISTNAME=	lmdb-0.94
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmdb/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/dw/py-lmdb/
COMMENT=	Universal Python binding for the LMDB
LICENSE=	modified-bsd

.include "../../databases/lmdb/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
