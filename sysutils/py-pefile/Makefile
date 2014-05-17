# $NetBSD: Makefile,v 1.1 2014/05/17 16:57:55 khorben Exp $

PEFILE_VERSION=	1.2.10-139
DISTNAME=	pefile-${PEFILE_VERSION}
PKGNAME=	${PYPKGPREFIX}-pefile-${PEFILE_VERSION:S/-/./}
CATEGORIES=	sysutils
MASTER_SITES=	https://pefile.googlecode.com/files/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://code.google.com/p/pefile/
COMMENT=	Python module to read and work with PE files
LICENSE=	modified-bsd

EGG_NAME=	pefile-${PEFILE_VERSION:S/-/_/}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
