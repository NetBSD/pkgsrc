# $NetBSD: Makefile,v 1.7 2024/07/28 10:26:08 adam Exp $

DISTNAME=	incremental-24.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/incremental/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hawkowl/incremental
COMMENT=	Small library that versions your Python projects
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
