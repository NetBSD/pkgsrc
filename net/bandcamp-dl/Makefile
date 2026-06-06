# $NetBSD: Makefile,v 1.10 2026/06/06 06:46:19 adam Exp $

DISTNAME=	bandcamp_downloader-0.0.17
PKGNAME=	${DISTNAME:S/_downloader/-dl/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bandcamp-downloader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Evolution0/bandcamp-dl
COMMENT=	Simple Python script to download Bandcamp albums
LICENSE=	unlicense

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.14.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-demjson3>=3.0.6:../../textproc/py-demjson3
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.47.0:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-unicode-slugify>=0.1.5:../../converters/py-unicode-slugify
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.2.2:../../www/py-urllib3

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
