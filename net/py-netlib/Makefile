# $NetBSD: Makefile,v 1.5 2015/08/23 14:31:25 leot Exp $

DISTNAME=	netlib-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mitmproxy/netlib
COMMENT=	Network utilities used by pathod and mitmproxy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.9:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-hpack>=1.0.1:../../net/py-hpack
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.2:../../security/py-passlib

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.13.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
