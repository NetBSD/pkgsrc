# $NetBSD: Makefile,v 1.8 2018/04/18 19:59:36 kamil Exp $

GITHUB_PROJECT=	libtaxii
DISTNAME=	libtaxii-1.1.101
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=TAXIIProject/}

MAINTAINER=	khorben@defora.org
#HOMEPAGE=	https://github.com/TAXIIProject/python-stix
COMMENT=	Python library for handling TAXII Messages and Services
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
