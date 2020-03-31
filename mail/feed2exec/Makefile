# $NetBSD: Makefile,v 1.6 2020/03/31 10:31:30 schmonz Exp $

DISTNAME=		feed2exec-0.15.0
PKGREVISION=		2
CATEGORIES=		mail python
MASTER_SITES=		https://gitlab.com/anarcat/feed2exec/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://feed2exec.readthedocs.io/
COMMENT=		The programmable feed reader
LICENSE=		gnu-agpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=		${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
BUILD_DEPENDS+=		${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=		${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=		${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=		${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=		${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text
DEPENDS+=		${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=		${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=		${PYPKGPREFIX}-requests-file-[0-9]*:../../devel/py-requests-file
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
TEST_DEPENDS+=		${PYPKGPREFIX}-betamax-[0-9]*:../../www/py-betamax
TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=		${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=		${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=		# none

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	feed2exec/__init__.py
SUBST_VARS.version=	PKGVERSION_NOREV

pre-install:
	find ${WRKSRC} -type f -name '*.orig' -print | xargs rm -f

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
