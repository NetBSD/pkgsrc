# $NetBSD: Makefile,v 1.5 2016/07/09 13:04:04 wiz Exp $

LIBTAXII_VERSION=	1.1.101
DISTNAME=	libtaxii-${LIBTAXII_VERSION}
PKGNAME=	${PYPKGPREFIX}-libtaxii-${LIBTAXII_VERSION}
CATEGORIES=	security
DISTFILES=	${LIBTAXII_VERSION}${EXTRACT_SUFX}
MASTER_SITES=	https://github.com/TAXIIProject/libtaxii/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/TAXIIProject/python-stix
COMMENT=	Python library for handling TAXII Messages and Services
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
