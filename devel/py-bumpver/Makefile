# $NetBSD: Makefile,v 1.11 2026/01/20 22:34:36 wiz Exp $

DISTNAME=	bumpver-2025.1131
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-pathlib2>=0:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} bumpver bumpver-${PYVERSSUFFIX} || ${TRUE}

# as of 2025.1131
# 2 failed, 523 passed, 1 warning

.include "../../lang/python/wheel.mk"
# for tests
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
