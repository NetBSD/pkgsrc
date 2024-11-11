# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:12 wiz Exp $

DISTNAME=	jaraco_collections-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.collections/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.collections
COMMENT=	Collection objects similar to those in stdlib
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/_/./}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jaraco.text-[0-9]*:../../textproc/py-jaraco.text
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=2.4:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
