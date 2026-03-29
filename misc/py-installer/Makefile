# $NetBSD: Makefile,v 1.6 2026/03/29 17:21:34 wiz Exp $

DISTNAME=	installer-1.0.0
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

# XXX Hack -- the patch phase leaves .orig files around which Python
# dutifully picks up and installs because it doesn't use any explicit
# lists of files or any patterns to exclude *.orig.
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/installer/*.orig

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
