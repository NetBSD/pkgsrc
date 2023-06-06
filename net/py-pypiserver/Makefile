# $NetBSD: Makefile,v 1.11 2023/06/06 12:42:08 riastradh Exp $

DISTNAME=	pypiserver-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pypiserver/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypiserver/pypiserver
COMMENT=	Minimal PyPI server for use with pip/easy_install
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.25.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-watchdog-[0-9]*:../../sysutils/py-watchdog
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest
TEST_DEPENDS+=	${PYPKGPREFIX}-pip>=7:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-twine-[0-9]*:../../net/py-twine

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pypi-server pypi-server-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
