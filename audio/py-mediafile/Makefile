# $NetBSD: Makefile,v 1.5 2025/02/23 18:49:49 wiz Exp $

DISTNAME=	mediafile-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mediafile/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/beetbox/mediafile
COMMENT=	Handles low-level interfacing for files' tags. Wraps Mutagen to
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.2.0:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.46:../../audio/py-mutagen

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
