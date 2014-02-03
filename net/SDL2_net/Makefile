# $NetBSD: Makefile,v 1.2 2014/02/03 08:59:33 rodent Exp $

DISTNAME=	SDL2_net-2.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library
LICENSE=	zlib

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	SDL2_net.pc.in

.include "options.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
