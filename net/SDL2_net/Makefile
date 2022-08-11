# $NetBSD: Makefile,v 1.13 2022/08/11 05:09:08 gutteridge Exp $

DISTNAME=	SDL2_net-2.0.1
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_net/
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
