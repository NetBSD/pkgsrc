# $NetBSD: Makefile,v 1.47 2022/01/04 20:52:32 wiz Exp $

DISTNAME=	picard-2.3.2
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/picard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://picard.musicbrainz.org/
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.20:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-mutagen

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
