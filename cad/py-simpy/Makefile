# $NetBSD: Makefile,v 1.20 2016/06/08 17:43:20 wiz Exp $

DISTNAME=		simpy-3.0.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		cad math
MASTER_SITES=		${MASTER_SITE_PYPI:=s/simpy/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://simpy.readthedocs.org/
COMMENT=		Discrete event simulation framework
LICENSE=		mit

# it is only for test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

do-test:
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -c "import simpy; simpy.test()"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
