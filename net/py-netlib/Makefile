# $NetBSD: Makefile,v 1.2 2014/01/21 11:38:03 wiz Exp $

DISTNAME=	netlib-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/n/netlib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/netlib
COMMENT=	Network utilities used by pathod and mitmproxy
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.9.2

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
