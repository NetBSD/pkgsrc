# $NetBSD: Makefile,v 1.50 2025/11/23 07:58:29 adam Exp $

DISTNAME=	pbr-7.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.openstack.org/pbr/
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures>=3.0.0:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6.8:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-testrepository>=0.0.18:../../devel/py-testrepository
TEST_DEPENDS+=	${PYPKGPREFIX}-testresources>=2.0.0:../../devel/py-testresources
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>=2.2.0:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.0.3:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32.0:../../devel/py-wheel
# not packaged: hacking, stestr

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

post-install:
	${CHMOD} -R g-w,o-w ${DESTDIR}${PREFIX}/${PYSITELIB}/pbr/tests/testpackage
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pbr pbr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
