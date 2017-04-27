# $NetBSD: Makefile,v 1.17 2017/04/27 12:59:04 wiz Exp $

DISTNAME=	pbr-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pbr/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/pbr
COMMENT=	Python Build Reasonableness
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

# TEST_DEPENDS
# some of these depend on pbr
#BUILD_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
#BUILD_DEPENDS+=	${PYPKGPREFIX}-testresources-[0-9]*:../../devel/py-testresources
#BUILD_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios
#BUILD_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
# unpackages:
# testrepository
# oslosphinx

REPLACE_PYTHON+=	pbr/tests/testpackage/setup.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pbr \
		${DESTDIR}${PREFIX}/bin/pbr${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
