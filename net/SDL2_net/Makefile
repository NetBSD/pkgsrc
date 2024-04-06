# $NetBSD: Makefile,v 1.18 2024/04/06 08:06:27 wiz Exp $

DISTNAME=	SDL2_net-2.2.0
PKGREVISION=	4
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
