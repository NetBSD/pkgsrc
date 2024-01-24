# $NetBSD: Makefile,v 1.32 2024/01/24 21:51:04 adam Exp $

DISTNAME=	m3u8-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m3u8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/globocom/m3u8
COMMENT=	Parser for M3U8 playlists
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-backports-datetime-fromisoformat-[0-9]*:../../time/py-backports-datetime-fromisoformat
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
