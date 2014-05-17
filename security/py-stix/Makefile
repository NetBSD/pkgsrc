# $NetBSD: Makefile,v 1.1 2014/05/17 16:03:45 khorben Exp $

STIX_VERSION=	1.1.0.6
DISTNAME=	python-stix-${STIX_VERSION}
PKGNAME=	${PYPKGPREFIX}-stix-${STIX_VERSION}
CATEGORIES=	security
DISTFILES=	v${STIX_VERSION}${EXTRACT_SUFX}
MASTER_SITES=	https://github.com/STIXProject/python-stix/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/STIXProject/python-stix
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

EGG_NAME=	stix-${STIX_VERSION}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
