# $NetBSD: Makefile,v 1.11 2025/12/09 12:03:38 adam Exp $

DISTNAME=	lmdb-1.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmdb/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/jnwatson/py-lmdb
COMMENT=	Universal Python binding for the LMDB
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cffi>=0.8:../../devel/py-cffi
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	patch

.include "../../databases/lmdb/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
