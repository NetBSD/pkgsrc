# $NetBSD: Makefile,v 1.48 2026/10/16 18:55:34 adam Exp $

DISTNAME=	streamlink-8.6.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=streamlink/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://streamlink.github.io/
COMMENT=	Tool that pipes video streams into a video player
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Socks>=1.5.8:../../net/py-Socks
DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-country>=0:../../geography/py-country
DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.3:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=0:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-isodate>=0:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-lxml>=5.0.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.30.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-trio>=0.25.0:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-trio-websocket>=0.9.0:../../www/py-trio-websocket
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.0.0:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.2.1:../../www/py-websocket-client
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.5.0:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=0:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio>=0:../../devel/py-test-trio

REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/flv.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/tag.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/__init__.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/packet.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/error.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/f4v.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/util.py
REPLACE_PYTHON+=	src/streamlink/plugins/tv3cat.py
REPLACE_PYTHON+=	src/streamlink/plugins/tvplayer.py

# as of 4.0.1
# 1 failed, 4591 passed, 31 skipped
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
