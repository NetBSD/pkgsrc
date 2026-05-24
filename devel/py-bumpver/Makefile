# $NetBSD: Makefile,v 1.12 2026/05/24 05:51:19 adam Exp $

DISTNAME=	bumpver-2026.1132
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bumpver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mbarkhau/bumpver
COMMENT=	Bump version numbers in project files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-lexid>=0:../../devel/py-lexid
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	bumpver

# as of 2025.1131
# 2 failed, 523 passed, 1 warning

.include "../../lang/python/wheel.mk"
# for tests
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
