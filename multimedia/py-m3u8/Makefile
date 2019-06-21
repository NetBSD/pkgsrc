# $NetBSD: Makefile,v 1.11 2019/06/21 08:33:35 adam Exp $

DISTNAME=	m3u8-0.3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m3u8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/globocom/m3u8
COMMENT=	Parser for M3U8 playlists
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
