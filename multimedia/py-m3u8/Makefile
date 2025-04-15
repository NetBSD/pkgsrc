# $NetBSD: Makefile,v 1.41 2025/04/15 15:49:09 adam Exp $

DISTNAME=	m3u8-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m3u8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/globocom/m3u8
COMMENT=	Parser for M3U8 playlists
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-backports-datetime-fromisoformat-[0-9]*:../../time/py-backports-datetime-fromisoformat
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
