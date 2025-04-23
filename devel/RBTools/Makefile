# $NetBSD: Makefile,v 1.25 2025/04/23 14:57:52 wiz Exp $

DISTNAME=	RBTools-5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=reviewboard/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.reviewboard.org/docs/rbtools/dev/
COMMENT=	Tool to submit patches to a Review Board
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-certifi>=2023.5.7:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-colorama>=0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-housekeeping>=1.1:../../devel/py-housekeeping
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-puremagic>=0:../../sysutils/py-puremagic
DEPENDS+=	${PYPKGPREFIX}-pydiffx>=1.1.0:../../devel/py-pydiffx
DEPENDS+=	${PYPKGPREFIX}-texttable>=0:../../textproc/py-texttable
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-tqdm>=0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=5.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.9:../../devel/py-importlib-resources
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>=0:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-kgb>=0:../../devel/py-kgb
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial>=0:../../devel/py-mercurial
TEST_DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
TEST_DEPENDS+=	git-svn-[0-9]*:../../devel/git-svn

USE_LANGUAGES=	# none

# for tests
USE_TOOLS+=	git

REPLACE_PYTHON+=		rbtools/testing/scripts/editor.py

WRKSRC=		${WRKDIR}/rbtools-release-${PKGVERSION_NOREV}

# as of 5.2
# 14 failed, 925 passed, 37 skipped, 24 warnings

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
