# $NetBSD: Makefile,v 1.24 2023/11/07 22:38:02 wiz Exp $

DISTNAME=		feed2exec-0.19.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		mail python
MASTER_SITES=		${MASTER_SITE_GITLAB:=anarcat/feed2exec/-/archive/${PKGVERSION_NOREV}/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://feed2exec.readthedocs.io/
COMMENT=		The programmable feed reader
LICENSE=		gnu-agpl-v3

TOOL_DEPENDS+=		${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TOOL_DEPENDS+=		${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=		${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
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
DEPENDS+=		${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
DEPENDS+=		${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=		${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=		${PYPKGPREFIX}-betamax>=0.8.0:../../www/py-betamax
TEST_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=		${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=		${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	setup.py feed2exec/__init__.py
SUBST_SED.version=	-e 's|@VERSION@|${PKGVERSION_NOREV}|'

post-extract:
	${ECHO} "version_number = \"${PKGVERSION_NOREV}\"" > ${WRKSRC}/feed2exec/_version.py

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
