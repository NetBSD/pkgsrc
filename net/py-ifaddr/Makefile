# $NetBSD: Makefile,v 1.7 2025/04/24 15:07:08 adam Exp $

DISTNAME=	ifaddr-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ifaddr/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/pydron/ifaddr
COMMENT=	Enumerates all IP addresses on all network adapters of the system
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
