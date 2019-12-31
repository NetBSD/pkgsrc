# $NetBSD: Makefile,v 1.2 2019/12/31 09:56:46 mef Exp $

DISTNAME=	ifaddr-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ifaddr/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/pydron/ifaddr
COMMENT=	Enumerates all IP addresses on all network adapters of the system
LICENSE=	mit

DEPENDS+=	py[0-9]*-expat:../../textproc/py-expat

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
