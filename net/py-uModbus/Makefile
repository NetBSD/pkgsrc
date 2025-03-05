# $NetBSD: Makefile,v 1.2 2025/03/05 10:20:33 wiz Exp $

DISTNAME=	uModbus-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uModbus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdvancedClimateSystems/umodbus/
COMMENT=	Implementation of the Modbus protocol in pure Python
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
