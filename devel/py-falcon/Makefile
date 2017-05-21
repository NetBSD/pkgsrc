# $NetBSD: Makefile,v 1.2 2017/05/21 06:54:13 adam Exp $

DISTNAME=	falcon-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/falcon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://falconframework.org/
COMMENT=	Unladen web framework for building APIs and app backends
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-python-mimeparse>=1.5.2:../../www/py-python-mimeparse
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-ddt-[0-9]*:../../devel/py-ddt
BUILD_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
BUILD_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
BUILD_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/falcon-bench \
		${DESTDIR}${PREFIX}/bin/falcon-bench-${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/falcon-print-routes \
		${DESTDIR}${PREFIX}/bin/falcon-print-routes-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
