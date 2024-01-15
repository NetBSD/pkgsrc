# $NetBSD: Makefile,v 1.13 2024/01/15 20:42:45 adam Exp $

DISTNAME=	pypiserver-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypiserver/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypiserver/pypiserver
COMMENT=	Minimal PyPI server for use with pip/easy_install
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.25.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-pip>=7:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-watchdog-[0-9]*:../../sysutils/py-watchdog
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest
TEST_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pypi-server pypi-server-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
