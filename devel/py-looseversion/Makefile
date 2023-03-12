# $NetBSD: Makefile,v 1.2 2023/03/12 02:58:53 gutteridge Exp $

DISTNAME=	looseversion-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/looseversion/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/effigies/looseversion
COMMENT=	Python extension for comparing version strings
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
