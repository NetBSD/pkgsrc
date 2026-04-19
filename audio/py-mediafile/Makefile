# $NetBSD: Makefile,v 1.9 2026/04/19 17:20:08 wiz Exp $

DISTNAME=	mediafile-0.16.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mediafile/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/beetbox/mediafile
COMMENT=	Handles low-level interfacing for files' tags. Wraps Mutagen to
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.2.0:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.46:../../audio/py-mutagen

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
