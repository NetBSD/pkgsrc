# $NetBSD: Makefile,v 1.2 2016/11/20 21:13:04 joerg Exp $

DISTNAME=	m3u8-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m3u8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/m3u8/
COMMENT=	Parser for M3U8 playlists
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
