# $NetBSD: Makefile,v 1.8 2022/09/11 16:53:08 wiz Exp $

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
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
