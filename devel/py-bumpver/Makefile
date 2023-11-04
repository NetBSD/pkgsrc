# $NetBSD: Makefile,v 1.4 2023/11/04 16:09:49 wiz Exp $

DISTNAME=	bumpver-2023.1129
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bumpver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mbarkhau/bumpver
COMMENT=	Bump version numbers in project files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-lib3to6>=0:../../devel/py-lib3to6
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-lexid>=0:../../devel/py-lexid
DEPENDS+=	${PYPKGPREFIX}-looseversion>=0:../../devel/py-looseversion
DEPENDS+=	${PYPKGPREFIX}-pathlib2>=0:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} bumpver bumpver-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
# for tests
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
