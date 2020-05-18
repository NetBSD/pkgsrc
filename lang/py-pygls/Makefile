# $NetBSD: Makefile,v 1.1 2020/05/18 15:11:01 wiz Exp $

DISTNAME=	pygls-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openlawlibrary/pygls/
COMMENT=	Pythonic generic implementation of the Language Server Protocol
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

PYTHON_VERSIONED_DEPENDENCIES=	test:test

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,lib/site-packages/pygls,lib/site-packages/pygls-${PYVERSSUFFIX},"
SUBST_FILES.path+=	setup.py
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing documentation installation path.

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
