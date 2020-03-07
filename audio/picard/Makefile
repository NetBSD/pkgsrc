# $NetBSD: Makefile,v 1.43 2020/03/07 09:18:43 wiz Exp $

DISTNAME=	picard-2.3.1
CATEGORIES=	audio
MASTER_SITES=	https://musicbrainz.osuosl.org/pub/musicbrainz/picard/
MASTER_SITES+=	ftp://ftp.eu.metabrainz.org/pub/musicbrainz/picard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://picard.musicbrainz.org/
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/picard-release-${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.20:../../audio/py-mutagen

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	setup.py
CONFIGURE_ARGS+=	config

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
