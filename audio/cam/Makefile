# $NetBSD: Makefile,v 1.16 2004/03/31 10:40:29 minskim Exp $
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
