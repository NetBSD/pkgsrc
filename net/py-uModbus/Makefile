# $NetBSD: Makefile,v 1.1 2024/11/05 11:13:22 wiz Exp $

DISTNAME=	uModbus-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uModbus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdvancedClimateSystems/umodbus/
COMMENT=	Implementation of the Modbus protocol in pure Python
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
