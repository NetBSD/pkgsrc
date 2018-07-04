# $NetBSD: Makefile,v 1.21 2018/07/04 09:05:16 adam Exp $

DISTNAME=	pbr-4.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.openstack.org/developer/pbr/
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-testrepository>=0.0.18:../../devel/py-testrepository
TEST_DEPENDS+=	${PYPKGPREFIX}-testresources>=2.0.0:../../devel/py-testresources
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools>=2.2.0:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=14.0.6:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pbr pbr${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
