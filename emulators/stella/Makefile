# $NetBSD: Makefile,v 1.17 2004/06/05 11:56:31 dillo Exp $

PKGNAME=	stella-${STELLA_VERSION}
CONFLICTS=	stella-sdl-[0-9]*

.include "Makefile.common"

USE_X11=	yes
MAKE_ENV+=	SOUND_OSS=1
ALL_TARGET=	unix-x
STELLA=		stella.x11

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
