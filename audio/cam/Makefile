# $NetBSD: Makefile,v 1.26 2014/10/09 14:05:55 wiz Exp $
#

DISTNAME=	cam-1.02
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/sound/mixers/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Cpu's Audio Mixer [curses based]

CONFLICTS+=	feh<1.2.6nb3

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CAMLIBS=	-lcurses
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "MirBSD"
CAMLIBS+=	-lossaudio
.endif

MAKE_ENV+=	CAMLIBS=${CAMLIBS:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
