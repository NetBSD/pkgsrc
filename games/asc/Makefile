# $NetBSD: Makefile,v 1.64 2019/08/11 13:21:02 wiz Exp $

DISTNAME=	asc-source-1.16.4.0
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asc-hq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.asc-hq.org/
COMMENT=	Turn based strategy game

DIST_SUBDIR=		asc
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 \
			machine_wars.mp3 time_to_strike.mp3
.for file in frontiers.mp3 machine_wars.mp3 time_to_strike.mp3
SITES.${file}=	http://asc-hq.org/
.endfor
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:build pkg-config
REPLACE_PERL=		checkfordata.pl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-paraguitest
CPPFLAGS.NetBSD+=	-D_UNICODE_BROKEN_

MAKE_ENV+=		top_src_dir=.

# ../weaponguide.cpp:1205: virtual memory exhausted
UNLIMIT_RESOURCES=	datasize

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--disable-gcc296-detection
.endif

post-extract:
	mv ${WRKDIR}/*.mp3 ${WRKSRC}/data/music

# bug in 1.16.4.0, remove on update
post-install:
	${INSTALL_DATA} ${WRKSRC}/data/asc.gfx ${DESTDIR}${PREFIX}/share/games/asc

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDLmm/buildlink3.mk"
.include "../../devel/libsigc++1/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/paragui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
