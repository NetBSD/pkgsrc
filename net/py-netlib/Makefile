# $NetBSD: Makefile,v 1.7 2015/12/05 21:25:54 adam Exp $

DISTNAME=	netlib-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mitmproxy/netlib
COMMENT=	Network utilities used by pathod and mitmproxy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-backports.ssl_match_hostname>=3.4.0.2:../../security/py-backports.ssl_match_hostname
DEPENDS+=	${PYPKGPREFIX}-certifi>=2015.9.6.2:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-hpack>=1.0.1:../../net/py-hpack
DEPENDS+=	${PYPKGPREFIX}-ipaddress>=1.0.14:../../net/py-ipaddress
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.2:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.14.0

# XXX: Get rid of garbage files (probably will not needed for future versions)
pre-configure:
	rm -rf ${WRKSRC}/netlib/__pycache__/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
