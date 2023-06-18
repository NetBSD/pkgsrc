# $NetBSD: Makefile,v 1.8 2023/06/18 05:39:37 adam Exp $

DISTNAME=	txtorcon-23.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txtorcon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://txtorcon.readthedocs.io/
COMMENT=	Twisted Python library for controlling tor daemon
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-zope.interface>=3.6.1:../../devel/py-zope.interface
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-twisted>=15.5.0:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

CHECK_INTERPRETER_SKIP+=	share/txtorcon/examples/*

PYTHON_VERSIONS_INCOMPATIBLE=	27

# 2 failed, 678 passed, 2 skipped, 129 warnings
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
