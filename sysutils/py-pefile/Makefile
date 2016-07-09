# $NetBSD: Makefile,v 1.5 2016/07/09 13:04:07 wiz Exp $

PEFILE_VERSION=	1.2.10-139
DISTNAME=	pefile-${PEFILE_VERSION}
PKGNAME=	${PYPKGPREFIX}-pefile-${PEFILE_VERSION:S/-/./}
CATEGORIES=	sysutils
MASTER_SITES=	https://pefile.googlecode.com/files/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://code.google.com/p/pefile/
COMMENT=	Python module to read and work with PE files
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

EGG_NAME=	pefile-${PEFILE_VERSION:S/-/.post/}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
