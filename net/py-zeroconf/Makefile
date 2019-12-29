# $NetBSD: Makefile,v 1.1 2019/12/29 04:39:49 ryoon Exp $

DISTNAME=	zeroconf-0.24.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeroconf/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jstasiak/python-zeroconf
COMMENT=	Pure Python Multicast DNS Service Discovery Library
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-ifaddr-[0-9]*:../../net/py-ifaddr

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
