# $NetBSD: Makefile,v 1.1 2018/08/11 00:48:50 nia Exp $

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

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/craft_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/craft_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
