# $NetBSD: Makefile,v 1.9 2018/07/03 05:03:32 adam Exp $

GITHUB_PROJECT=	libtaxii
DISTNAME=	libtaxii-1.1.101
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=TAXIIProject/}

MAINTAINER=	khorben@defora.org
#HOMEPAGE=	https://github.com/TAXIIProject/python-stix
COMMENT=	Python library for handling TAXII Messages and Services
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
