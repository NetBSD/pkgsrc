# $NetBSD: Makefile,v 1.17 2004/06/02 20:28:59 jschauma Exp $
#

DISTNAME=	cam-1.02
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/sound/mixers/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Cpu's Audio Mixer [curses based]

CONFLICTS+=	feh<1.2.6nb3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.prefs.mk"

CAMLIBS=	-lcurses
.if ${OPSYS} == "NetBSD"
CAMLIBS+=	-lossaudio
.endif

MAKE_ENV+=	CAMLIBS="${CAMLIBS}"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
