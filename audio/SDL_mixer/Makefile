# $NetBSD: Makefile,v 1.3 2003/05/02 11:53:36 wiz Exp $
#

DISTNAME=		SDL_mixer-1.2.4
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_mixer/
COMMENT=		multi-channel audio mixer library

CONFLICTS=		SDL-mixer-[0-9]*

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		YES

CPPFLAGS+=		-Dunix=1

post-configure:
	${SED} -e "s|@PREFIX@|${PREFIX}|" ${WRKSRC}/timidity/config.h \
		> ${WRKSRC}/timidity/config.h.patched
	${MV} ${WRKSRC}/timidity/config.h.patched ${WRKSRC}/timidity/config.h

.include "../../audio/libogg/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
