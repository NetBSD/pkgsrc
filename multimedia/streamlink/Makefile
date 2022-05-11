# $NetBSD: Makefile,v 1.32 2022/05/11 22:30:17 bouyer Exp $

DISTNAME=	streamlink-4.0.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=streamlink/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://streamlink.github.io/
COMMENT=	Tool that pipes video streams into a video player
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-iso3166

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"

DEPENDS+=	${PYPKGPREFIX}-cryptodome>=3.4.3:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.0.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-versioningit>=1.1.1:../../devel/py-versioningit
DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-iso-639-[0-9]*:../../devel/py-iso-639
DEPENDS+=	${PYPKGPREFIX}-iso3166-[0-9]*:../../devel/py-iso3166
DEPENDS+=	${PYPKGPREFIX}-country-[0-9]*:../../geography/py-country
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.2.1*:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-Socks-[0-9]*:../../net/py-Socks
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock

EGG_NAME=	streamlink-0.0.0+unknown

REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/flv.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/tag.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/__init__.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/packet.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/error.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/f4v.py
REPLACE_PYTHON+=	src/streamlink/packages/flashmedia/util.py
REPLACE_PYTHON+=	src/streamlink/plugins/tv3cat.py
REPLACE_PYTHON+=	src/streamlink/plugins/tvplayer.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
