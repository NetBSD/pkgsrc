# $NetBSD: Makefile,v 1.17 2024/10/14 06:45:54 wiz Exp $

DISTNAME=	pypiserver-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypiserver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypiserver/pypiserver
COMMENT=	Minimal PyPI server for use with pip/easy_install
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.25.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-pip>=7:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-watchdog-[0-9]*:../../sysutils/py-watchdog
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest
TEST_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pypi-server pypi-server-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
