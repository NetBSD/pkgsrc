# $NetBSD: Makefile,v 1.6 2022/01/04 20:54:42 wiz Exp $

DISTNAME=	ndg_httpsclient-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cedadev/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cedadev/ndg_httpsclient/
COMMENT=	HTTPS client implementation for httplib and urllib2 based on PyOpenSSL
LICENSE=	modified-bsd

GITHUB_PROJECT=	ndg_httpsclient
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.4:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
