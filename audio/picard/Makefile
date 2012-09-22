# $NetBSD: Makefile,v 1.15 2012/09/22 13:48:15 ryoon Exp $
#

DISTNAME=	picard-0.16
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/Picard_Tagger
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.5:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.20:../../audio/py-mutagen

PKG_DESTDIR_SUPPORT= user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	setup.py
CONFIGURE_ARGS+=	config

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
