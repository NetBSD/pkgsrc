# $NetBSD: Makefile,v 1.14 2022/02/04 00:04:09 wiz Exp $

DISTNAME=		feed2exec-0.18.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail python
MASTER_SITES=		${MASTER_SITE_PYPI:=f/feed2exec/}
# remove after 0.18.0
DIST_SUBDIR=		${DISTNAME}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://feed2exec.readthedocs.io/
COMMENT=		The programmable feed reader
LICENSE=		gnu-agpl-v3

BUILD_DEPENDS+=		${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=		${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
BUILD_DEPENDS+=		${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=		${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=		${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=		${PYPKGPREFIX}-cachecontrol-[0-9]*:../../devel/py-cachecontrol
DEPENDS+=		${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=		${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
DEPENDS+=		${PYPKGPREFIX}-feedparser>=6.0.0:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text
DEPENDS+=		${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=		${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=		${PYPKGPREFIX}-requests-file-[0-9]*:../../devel/py-requests-file
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
DEPENDS+=		${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=		${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=		${PYPKGPREFIX}-betamax>=0.8.0:../../www/py-betamax
TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=		${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=		${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
