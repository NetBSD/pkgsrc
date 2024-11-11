# $NetBSD: Makefile,v 1.8 2024/11/11 07:27:57 wiz Exp $

DISTNAME=	lmdb-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lmdb/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/jnwatson/py-lmdb
COMMENT=	Universal Python binding for the LMDB
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_TOOLS+=	patch

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../databases/lmdb/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
