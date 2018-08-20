# $NetBSD: Makefile,v 1.22 2018/08/20 22:36:20 szptvlfn Exp $

DISTNAME=		simpy-3.0.10
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		cad math
MASTER_SITES=		${MASTER_SITE_PYPI:=s/simpy/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://simpy.readthedocs.org/
COMMENT=		Discrete event simulation framework
LICENSE=		mit

# it is only for test
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

#do-test:
#	${SETENV} ${TEST_ENV} ${PYTHONBIN} -c "import simpy; simpy.test()"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
