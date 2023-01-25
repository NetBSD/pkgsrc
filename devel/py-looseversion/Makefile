# $NetBSD: Makefile,v 1.1 2023/01/25 05:26:18 gutteridge Exp $

DISTNAME=	looseversion-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/looseversion/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/effigies/looseversion
COMMENT=	Python extension for comparing version strings
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
