# $NetBSD: Makefile,v 1.1 2015/12/01 08:43:05 fhajny Exp $

DISTNAME=	ndg_httpsclient-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cedadev/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/cedadev/ndg_httpsclient/
COMMENT=	HTTPS client implementation for httplib and urllib2 based on PyOpenSSL
LICENSE=	modified-bsd

GITHUB_PROJECT=	ndg_httpsclient
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.4:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
