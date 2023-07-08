# $NetBSD: Makefile,v 1.4 2023/07/08 13:11:04 gutteridge Exp $

DISTNAME=	looseversion-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/looseversion/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/effigies/looseversion
COMMENT=	Python extension for comparing version strings
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

# As of 1.2.0, the package does support Python 2.7, but hatchling does not.
PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
