# $NetBSD: Makefile,v 1.15 2012/10/02 23:48:02 asau Exp $

DISTNAME=		ocp-0.1.21
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opencubicplayer/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://sourceforge.net/p/opencubicplayer/
COMMENT=		Open Cubic Player
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
USE_LANGUAGES=		c c++
USE_NCURSES=		yes	# resize_term
INFO_FILES=		yes

REPLACE_SH=		ocp-curses ocp-sdl ocp-vcsa ocp-x11

# ymtype.so wants to link -llzh before it's finished building
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

CFLAGS.SunOS+=		-mimpure-text
CFLAGS.SunOS+=		-DSOUND_PCM_WRITE_CHANNELS=SNDCTL_DSP_CHANNELS
CFLAGS.SunOS+=		-DSOUND_PCM_WRITE_BITS=SNDCTL_DSP_SETFMT
CFLAGS.SunOS+=		-DSOUND_PCM_WRITE_RATE=SNDCTL_DSP_SPEED

PLIST_VARS+=		sdl x11 desktop

.include "options.mk"

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
