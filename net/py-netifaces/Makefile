# $NetBSD: Makefile,v 1.14 2025/04/25 11:42:07 adam Exp $

DISTNAME=	netifaces-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/netifaces/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/al45tair/netifaces
COMMENT=	Portable access to network interfaces from Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
