# $NetBSD: Makefile,v 1.9 2023/11/07 22:38:04 wiz Exp $

DISTNAME=	eliot-1.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
#MASTER_SITES+=	${MASTER_SITE_PYPI:=e/eliot/}
MASTER_SITES+=	${MASTER_SITE_GITHUB:=itamarst/}
GITHUB_TAG=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	eliot

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/itamarst/eliot
COMMENT=	Logging library that tells you why it happened
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-boltons>=19.0.1:../../devel/py-boltons
DEPENDS+=	${PYPKGPREFIX}-pyrsistent>=0.11.8:../../devel/py-pyrsistent
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=1.14.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} eliot-prettyprint eliot-prettyprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
