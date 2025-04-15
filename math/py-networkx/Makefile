# $NetBSD: Makefile,v 1.45 2025/04/15 16:31:38 adam Exp $

DISTNAME=	networkx-3.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/networkx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://networkx.github.io/
COMMENT=	Python package for creating and manipulating graphs and networks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
