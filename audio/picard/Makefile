# $NetBSD: Makefile,v 1.40 2019/09/02 13:20:05 adam Exp $

DISTNAME=	picard-1.3.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/Picard_Tagger
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/picard-release-${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.5:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.20:../../audio/py-mutagen

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.3.1

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	setup.py
CONFIGURE_ARGS+=	config

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
