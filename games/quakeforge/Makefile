# $NetBSD: Makefile,v 1.4 2004/10/03 00:14:46 tv Exp $

DISTNAME=		quakeforge-0.5.5
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=quake/}

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://www.quakeforge.net/
COMMENT=		Improved Quake engine

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

CONFIGURE_ARGS+=	--with-cpp="${CPP} %d %i %o"
CONFIGURE_ARGS+=	--disable-ogg
CONFIGURE_ARGS+=	--disable-xmms
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11=		YES
YACC=			${LOCALBASE}/bin/bison

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	libs/audio/targets/snd_oss.c
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"
.if !(defined(USE_INET6) && ${USE_INET6} == "YES")
CONFIGURE_ARGS+=	--without-ipv6
.endif

pre-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/include/QF/plugin
	${INSTALL_PROGRAM_DIR} ${PREFIX}/include/QF/ruamoko/gui

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
