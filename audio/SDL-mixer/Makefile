# $NetBSD: Makefile,v 1.5 2003/03/24 10:50:47 wiz Exp $
#

DISTNAME=		SDL_mixer-1.2.4
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_mixer/
COMMENT=		multi-channel audio mixer library

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		YES
BUILDLINK_DEPENDS.SDL=	SDL>=1.2.2

CPPFLAGS+=		-Dunix=1

post-configure:
	${SED} -e "s|@PREFIX@|${PREFIX}|" ${WRKSRC}/timidity/config.h \
		> ${WRKSRC}/timidity/config.h.patched
	${MV} ${WRKSRC}/timidity/config.h.patched ${WRKSRC}/timidity/config.h

.include "../../audio/libogg/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
