# $NetBSD: Makefile,v 1.2 2002/08/27 18:39:43 jlam Exp $
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

USE_BUILDLINK2=		YES
BUILDLINK_DEPENDS.SDL=	SDL>=1.2.2

CPPFLAGS+=		-Dunix=1

.include "../../audio/libogg/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
