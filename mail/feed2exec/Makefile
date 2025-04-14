# $NetBSD: Makefile,v 1.33 2025/04/14 09:27:05 adam Exp $

DISTNAME=	feed2exec-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_GITLAB:=anarcat/feed2exec/-/archive/${PKGVERSION_NOREV}/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://feed2exec.readthedocs.io/
COMMENT=	The programmable feed reader
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-cachecontrol-[0-9]*:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateparser-[0-9]*:../../time/py-dateparser
DEPENDS+=	${PYPKGPREFIX}-feedparser>=6.0.0:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-file-[0-9]*:../../devel/py-requests-file
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
TEST_DEPENDS+=	${PYPKGPREFIX}-betamax>=0.8.0:../../www/py-betamax
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	setup.py feed2exec/__init__.py
SUBST_SED.version=	-e 's|@VERSION@|${PKGVERSION_NOREV}|'

REPLACE_PYTHON+=	feed2exec/controller.py
REPLACE_PYTHON+=	feed2exec/plugins/__init__.py
REPLACE_PYTHON+=	feed2exec/plugins/ikiwikitoot.py
REPLACE_PYTHON+=	feed2exec/tests/test_network.py
REPLACE_PYTHON+=	feed2exec/tests/test_feeds.py
REPLACE_PYTHON+=	feed2exec/tests/test_main.py
REPLACE_PYTHON+=	feed2exec/__main__.py

# 1 failed, 47 passed, 2 skipped, 1 xfailed, 119 warnings (NetBSD 10.1)

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} -f feed2exec feed2exec-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
