# $NetBSD: Makefile,v 1.12 2020/08/18 20:14:07 riastradh Exp $

PEFILE_VERSION=	2019.4.18
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
