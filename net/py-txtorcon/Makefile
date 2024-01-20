# $NetBSD: Makefile,v 1.9 2024/01/20 08:51:16 adam Exp $

DISTNAME=	txtorcon-23.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txtorcon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://txtorcon.readthedocs.io/
COMMENT=	Twisted Python library for controlling tor daemon
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-twisted>=15.5.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=3.6.1:../../devel/py-zope.interface
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

CHECK_INTERPRETER_SKIP+=	share/txtorcon/examples/*

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
