# $NetBSD: Makefile,v 1.4 2026/10/17 13:40:42 wiz Exp $

DISTNAME=	versioneer-0.29
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/versioneer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-versioneer/python-versioneer
COMMENT=	Version-string management for VCS-controlled trees
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	versioneer

# as of 0.29
# 1 warning, 2 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
