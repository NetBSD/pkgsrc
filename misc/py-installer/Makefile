# $NetBSD: Makefile,v 1.8 2026/10/13 12:21:17 wiz Exp $

DISTNAME=	installer-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/installer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/installer
COMMENT=	Library for installing Python wheels
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

INSTALL_ENV+=	PYTHONPATH=${WRKSRC}/src
TEST_ENV+=	PYTHONPATH=${WRKSRC}/src

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} -m installer --destdir ${DESTDIR} --prefix ${PREFIX} dist/*.whl

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/installer/*.orig

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
