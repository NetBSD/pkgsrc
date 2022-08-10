# $NetBSD: Makefile,v 1.6 2022/08/10 09:12:00 adam Exp $

DISTNAME=	ifaddr-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ifaddr/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/pydron/ifaddr
COMMENT=	Enumerates all IP addresses on all network adapters of the system
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
