# $NetBSD: Makefile,v 1.13 2021/06/02 22:21:12 khorben Exp $

PEFILE_VERSION=	2021.5.24
DISTNAME=	pefile-${PEFILE_VERSION}
PKGNAME=	${PYPKGPREFIX}-pefile-${PEFILE_VERSION:S/-/./}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pefile/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/erocarrera/pefile
COMMENT=	Python module to read and work with PE files
LICENSE=	modified-bsd

EGG_NAME=	pefile-${PEFILE_VERSION:S/-/.post/}

DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
