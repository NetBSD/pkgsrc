# $NetBSD: Makefile,v 1.4 2020/03/27 07:53:59 nia Exp $

DISTNAME=	game-music-emu-0.6.3
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/mpyne/game-music-emu/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://bitbucket.org/mpyne/game-music-emu/wiki/Home
COMMENT=	Video game music file emulation/playback library
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DENABLE_UBSAN=OFF

PKGCONFIG_OVERRIDE+=	gme/libgme.pc.in

.include "../../mk/bsd.pkg.mk"
