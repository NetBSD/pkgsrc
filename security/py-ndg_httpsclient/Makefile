# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:21 wiz Exp $

DISTNAME=	ndg_httpsclient-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cedadev/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/cedadev/ndg_httpsclient/
COMMENT=	HTTPS client implementation for httplib and urllib2 based on PyOpenSSL
LICENSE=	modified-bsd

GITHUB_PROJECT=	ndg_httpsclient
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.4:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
