# $NetBSD: Makefile,v 1.79 2022/01/10 01:46:31 ryoon Exp $

DISTNAME=	asc-2.6.1.0
PKGREVISION=	13
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asc-hq/}
EXTRACT_SUFX=	.tar.bz2

DIST_SUBDIR=	asc

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	frontiers.ogg
DISTFILES+=	machine_wars.ogg
DISTFILES+=	time_to_strike.ogg

.for file in frontiers.ogg machine_wars.ogg time_to_strike.ogg
SITES.${file}=	http://www.asc-hq.org/music/
.endfor

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.asc-hq.org/
COMMENT=	Turn based strategy game in the tradition of the Battle Isle series
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	perl pkg-config zip
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CPPFLAGS+=	-D__EXPORT__=
MAKE_ENV+=	top_builddir=.
MAKE_ENV+=	src_dir=.

SUBST_CLASSES+=		lua
SUBST_STAGE.lua=	pre-configure
SUBST_MESSAGE.lua=	Correcting lua library name.
SUBST_FILES.lua+=	configure
SUBST_SED.lua=		-e 's/lua5.1/lua-5.1/g'

CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
CONFIGURE_ARGS+=	--disable-ft2test

GNU_CONFIGURE_WX_VERSION= no

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-extract:
	mv ${WRKDIR}/*.ogg ${WRKSRC}/data/music

post-build:
	cd ${WRKSRC} && ${PREFIX}/bin/icotool -i 1 -x -o asc.png \
	    source/win32/msvc/ASC/icon2.ico

post-install:
	${INSTALL_DATA} ${FILESDIR}/asc.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/asc.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
