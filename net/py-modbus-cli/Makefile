# $NetBSD: Makefile,v 1.2 2025/01/03 12:00:45 adam Exp $

DISTNAME=	modbus_cli-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/modbus_cli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/favalex/modbus-cli
COMMENT=	Command line tool to access Modbus devices
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-uModbus>=0:../../net/py-uModbus

USE_LANGUAGES=	# none

# as of 0.1.9
# 2 failed, 12 passed
# https://github.com/favalex/modbus-cli/issues/33

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} modbus modbus-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
