# $NetBSD: Makefile,v 1.11 2011/11/16 01:33:16 sbd Exp $
#

DISTNAME=	picard-0.15.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/Picard_Tagger
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes
PKG_DESTDIR_SUPPORT= user-destdir

USE_TOOLS+=	msgfmt pkg-config

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py config)

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../audio/py-mutagen/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
