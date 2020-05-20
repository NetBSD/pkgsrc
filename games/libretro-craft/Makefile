# $NetBSD: Makefile,v 1.2 2020/05/20 06:09:06 rillig Exp $

DISTNAME=	libretro-craft-20180803
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	Craft
GITHUB_TAG=	581fb4255f7e856af4d568ee518e73dd38244c5d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/craft
COMMENT=	Libretro core based on the 'Craft' Minecraft clone
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FILE=	Makefile.libretro
MAKE_FLAGS+=	GIT_VERSION=" \(pkgsrc\)"

# src/main.c: In function 'char_width':
# src/main.c:301:18: error: array subscript has type 'char' [-Werror=char-subscripts]
#      return lookup[input];
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/craft_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/craft_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
