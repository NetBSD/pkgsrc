# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:23 wiz Exp $

DISTNAME=	bandcamp-downloader-0.0.10
PKGNAME=	${DISTNAME:S/-downloader/-dl/1}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bandcamp-downloader/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/iheanyi/bandcamp-dl
COMMENT=	Simple Python script to download Bandcamp albums
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-demjson-[0-9]*:../../textproc/py-demjson
DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-unicode-slugify-[0-9]*:../../converters/py-unicode-slugify
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-mutagen

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
