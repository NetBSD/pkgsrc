# $NetBSD: Makefile,v 1.4 2015/03/09 09:11:24 wiz Exp $

DISTNAME=	netlib-0.11.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/n/netlib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mitmproxy/netlib
COMMENT=	Network utilities used by pathod and mitmproxy
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.7:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.2:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.14:../../security/py-OpenSSL

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.11.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
