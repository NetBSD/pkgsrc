# $NetBSD: Makefile,v 1.4 2003/05/11 02:23:18 salo Exp $
#

DISTNAME=		SDL_mixer-1.2.5
CATEGORIES=		audio
MASTER_SITES=		http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_mixer/
COMMENT=		multi-channel audio mixer library

CONFLICTS=		SDL-mixer-[0-9]*

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CPPFLAGS=		-Dunix=1
CFLAGS=			-DPREFIX=\"\\\"${PREFIX}\\\"\"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/playmus ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/playwave ${PREFIX}/bin

.include "../../audio/libogg/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
