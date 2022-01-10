# $NetBSD: Makefile,v 1.3 2022/01/10 19:17:10 adam Exp $

# Important: Re-generate files/setup.py on update.
DISTNAME=	flit-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Simple packaging tool for simple packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flit_core-${PKGVERSION_NOREV}:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-tomli>=0:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-tomli_w>=0:../../textproc/py-tomli_w
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.7.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} flit flit-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
