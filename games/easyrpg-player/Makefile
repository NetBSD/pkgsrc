# $NetBSD: Makefile,v 1.11 2020/05/28 10:44:48 nia Exp $

DISTNAME=	easyrpg-player-0.6.2.1
CATEGORIES=	games
MASTER_SITES=	https://easyrpg.org/downloads/player/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://easyrpg.org/
COMMENT=	RPG Maker 2000/2003 and EasyRPG games interpreter
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c c++

# "We require now the C++ language standard C++14.
# The lowest GCC compiler supporting this fully is GCC5"
GCC_REQD+=	5

.include "options.mk"
.include "../../audio/libxmp/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../games/liblcf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
