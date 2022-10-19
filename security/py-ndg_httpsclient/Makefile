# $NetBSD: Makefile,v 1.9 2022/10/19 14:25:20 nia Exp $

DISTNAME=	ndg_httpsclient-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cedadev/}
GITHUB_PROJECT=	ndg_httpsclient
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cedadev/ndg_httpsclient/
COMMENT=	HTTPS client implementation for httplib and urllib2 based on PyOpenSSL
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.4:../../security/py-asn1

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
