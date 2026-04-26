# $NetBSD: Makefile,v 1.9 2026/04/26 10:10:42 wiz Exp $

DISTNAME=	game-music-emu-0.6.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgme/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://github.com/libgme/game-music-emu/
COMMENT=	Video game music file emulation/playback library
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DENABLE_UBSAN=OFF

PKGCONFIG_OVERRIDE+=	gme/libgme.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
