# $NetBSD: Makefile,v 1.2 2022/01/10 19:17:09 adam Exp $

# Important: Re-generate files/setup.py on update.
DISTNAME=	flit_core-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Distribution-building parts of Flit
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}/

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} flit_core/tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
