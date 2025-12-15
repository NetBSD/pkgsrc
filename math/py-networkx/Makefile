# $NetBSD: Makefile,v 1.48 2025/12/15 12:05:15 adam Exp $

DISTNAME=	networkx-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
