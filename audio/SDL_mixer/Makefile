# $NetBSD: Makefile,v 1.9 2003/12/08 14:41:38 wiz Exp $
#

DISTNAME=		SDL_mixer-1.2.5
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_mixer/
COMMENT=		Multi-channel audio mixer library

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
