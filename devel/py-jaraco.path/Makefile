# $NetBSD: Makefile,v 1.14 2025/03/05 09:47:23 wiz Exp $

DISTNAME=	jaraco_path-3.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.path/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.path
COMMENT=	Miscellaneous path functions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == Darwin
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa-[0-9]*:../../devel/py-pyobjc-framework-Cocoa
.endif

USE_LANGUAGES=	# none

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
