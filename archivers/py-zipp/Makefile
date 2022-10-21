# $NetBSD: Makefile,v 1.19 2022/10/21 09:05:19 adam Exp $

DISTNAME=	zipp-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_WHEEL:=zipp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/zipp
COMMENT=	Backport of pathlib-compatible object wrapper for zip files
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# XXX: avoid cirucilar depencency for Python 3.7: py-build -> py-importlib-metadata
NO_BUILD=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
