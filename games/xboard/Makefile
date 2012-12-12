# $NetBSD: Makefile,v 1.40 2012/12/12 12:25:14 wiz Exp $

DISTNAME=	xboard-4.6.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=xboard/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/xboard/
COMMENT=	Graphical frontend for chess engines and servers

CONFIGURE_ARGS+=	--enable-xpm
CONFIGURE_ARGS+=	--enable-zippy	# interface to ICS
CONFIGURE_ARGS+=	PERLPATH=${PERL5}
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run makeinfo
INFO_FILES=		yes
REPLACE_PERL=		texi2man

INSTALLATION_DIRS+=	share/examples/xboard
CONF_FILES+=		${PREFIX}/share/examples/xboard/xboard.conf ${PKG_SYSCONFDIR}/xboard.conf

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		XAW_TYPE
.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
.endif

SUBST_CLASSES+=		engine
SUBST_MESSAGE.engine=	Setting default chess engine.
SUBST_STAGE.engine=	pre-configure
SUBST_FILES.engine=	xboard.conf.in
SUBST_SED.engine=	-e '/ChessProgram / s,fairymax,gnuchess,'
DEPENDS+=		gnuchess-[0-9]*:../../games/gnuchess

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Solaris"
WAVPLAYER=      /usr/bin/audioplay
.elif ${OPSYS} == "OpenBSD"
WAVPLAYER=      /usr/bin/aucat -i
.elif ${OPSYS} == "Darwin"
WAVPLAYER=      ${LOCALBASE}/bin/qtplay
DEPENDS+=       qtplay-[0-9]*:../../audio/qtplay
.elif ${OPSYS} == "Linux"
WAVPLAYER=      ${LOCALBASE}/bin/aplay -q
DEPENDS+=       alsa-utils-[0-9]*:../../audio/alsa-utils
.else
CHECK_BUILTIN.oss:=     yes
.  include "../../mk/oss.builtin.mk"
CHECK_BUILTIN.oss:=     no
.  if defined(IS_BUILTIN.oss) && !empty(IS_BUILTIN.oss:M[yY][eE][sS])
WAVPLAYER=      ${LOCALBASE}/bin/sndfile-play
DEPENDS+=       libsndfile-[0-9]*:../../audio/libsndfile
#.  else # most crossplatform, but a bit too many dependencies
#WAVPLAYER=     ${LOCALBASE}/bin/playsound
#DEPENDS+=      SDL_sound-[0-9]*:../../audio/SDL_sound
.  endif
.endif

SUBST_CLASSES+=                 wavplayer
SUBST_MESSAGE.wavplayer=        Setting wav player location.
SUBST_STAGE.wavplayer=          post-build
SUBST_FILES.wavplayer=          xboard.conf
SUBST_SED.wavplayer=            -e 's,aplay -q,${WAVPLAYER},g'

post-install:
	$(INSTALL_SCRIPT) ${WRKSRC}/cmail ${DESTDIR}${PREFIX}/bin
	$(INSTALL_DATA) ${WRKSRC}/xboard.conf ${DESTDIR}${PREFIX}/share/examples/xboard

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
