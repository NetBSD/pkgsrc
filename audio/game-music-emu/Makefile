# $NetBSD: Makefile,v 1.3 2020/03/26 12:27:58 nia Exp $

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

PKGCONFIG_OVERRIDE+=	gme/libgme.pc.in

BUILDLINK_TRANSFORM+=	rm:-fsanitize=undefined

.include "../../mk/bsd.pkg.mk"
