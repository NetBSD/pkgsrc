# $NetBSD: Makefile,v 1.1.1.1 2001/09/24 15:00:25 rh Exp $
#

DISTNAME=		SDL_mixer-1.2.0
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		audio
MASTER_SITES=		http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_mixer/
COMMENT=		multi-channel audio mixer library

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK_ONLY=	YES
BUILDLINK_DEPENDS.SDL=	SDL>=1.2.2

CPPFLAGS+=		-Dunix=1

.include "../../audio/libogg/buildlink.mk"
.include "../../devel/smpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
