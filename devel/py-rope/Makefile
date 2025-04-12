# $NetBSD: Makefile,v 1.45 2025/04/12 20:13:33 adam Exp $

DISTNAME=	rope-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-rope/rope
COMMENT=	Python refactoring library
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toolconfig>=1.2.2:../../devel/py-toolconfig
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-toolconfig -> py-sphinx

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
