# $NetBSD: Makefile,v 1.2 2009/07/14 09:03:04 hasso Exp $
#

DISTNAME=	picard-0.11
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/Picard_Tagger
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes
USE_DIRS+=	xdg-1.1

USE_TOOLS+=	msgfmt

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
