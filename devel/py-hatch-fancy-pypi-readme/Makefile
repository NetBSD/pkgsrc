# $NetBSD: Makefile,v 1.10 2026/10/16 17:11:33 adam Exp $

DISTNAME=	hatch_fancy_pypi_readme-25.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-fancy-pypi-readme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hynek/hatch-fancy-pypi-readme
COMMENT=	Fancy PyPI READMEs with Hatch
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.21.0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-build>=0:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	hatch-fancy-pypi-readme

# as of 25.1.0
# 2 failed, 46 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
