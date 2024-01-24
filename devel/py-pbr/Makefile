# $NetBSD: Makefile,v 1.42 2024/01/24 16:29:40 wiz Exp $

DISTNAME=	pbr-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.openstack.org/pbr/
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures>=3.0.0:../../devel/py-fixtures
#TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit>=2.6.0:../../wip/py-pre-commit
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6.8:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-testrepository>=0.0.18:../../devel/py-testrepository
TEST_DEPENDS+=	${PYPKGPREFIX}-testresources>=2.0.0:../../devel/py-testresources
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.0.3:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32.0:../../devel/py-wheel
# circular dependency - testtools depends on pbr
#TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
# not packaged: hacking, stestr

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

post-install:
	${CHMOD} -R g-w,o-w ${DESTDIR}${PREFIX}/${PYSITELIB}/pbr/tests/testpackage
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pbr pbr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
