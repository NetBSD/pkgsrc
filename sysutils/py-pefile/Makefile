# $NetBSD: Makefile,v 1.2 2014/06/03 08:59:33 khorben Exp $

PEFILE_VERSION=	1.2.10-139
DISTNAME=	pefile-${PEFILE_VERSION}
PKGNAME=	${PYPKGPREFIX}-pefile-${PEFILE_VERSION:S/-/./}
CATEGORIES=	sysutils
MASTER_SITES=	https://pefile.googlecode.com/files/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://code.google.com/p/pefile/
COMMENT=	Python module to read and work with PE files
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

EGG_NAME=	pefile-${PEFILE_VERSION:S/-/_/}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
