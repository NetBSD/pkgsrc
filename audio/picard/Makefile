# $NetBSD: Makefile,v 1.24 2014/11/24 12:22:17 mef Exp $

DISTNAME=	picard-1.3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/Picard_Tagger
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.5:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.20:../../audio/py-mutagen

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.2

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	setup.py
CONFIGURE_ARGS+=	config

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
