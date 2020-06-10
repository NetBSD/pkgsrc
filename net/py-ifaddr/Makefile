# $NetBSD: Makefile,v 1.4 2020/06/10 10:18:17 adam Exp $

DISTNAME=	ifaddr-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ifaddr/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/pydron/ifaddr
COMMENT=	Enumerates all IP addresses on all network adapters of the system
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
