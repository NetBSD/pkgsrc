# $NetBSD: Makefile,v 1.22 2021/08/06 12:42:34 adam Exp $

DISTNAME=	zeroconf-0.33.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zeroconf/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jstasiak/python-zeroconf
COMMENT=	Pure Python Multicast DNS Service Discovery Library
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-ifaddr>=0.1.7:../../net/py-ifaddr
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
