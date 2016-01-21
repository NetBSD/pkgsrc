# $NetBSD: Makefile,v 1.9 2016/01/21 00:15:50 leot Exp $

DISTNAME=	netlib-0.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mitmproxy/netlib
COMMENT=	Network utilities used by pathod and mitmproxy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-backports.ssl_match_hostname>=3.5.0.1:../../security/py-backports.ssl_match_hostname
DEPENDS+=	${PYPKGPREFIX}-certifi>=2015.9.6.2:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.1.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.0.1:../../net/py-hpack
DEPENDS+=	${PYPKGPREFIX}-ipaddress>=1.0.15:../../net/py-ipaddress
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.2:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.15.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
