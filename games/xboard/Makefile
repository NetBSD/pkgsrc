# $NetBSD: Makefile,v 1.73 2022/06/28 11:33:57 wiz Exp $

DISTNAME=	xboard-4.9.1
#PKGREVISION=	1
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=xboard/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/xboard/
COMMENT=	Graphical frontend for chess engines and servers
LICENSE=	gnu-gpl-v3

CONFIGURE_ARGS+=	--enable-zippy	# interface to ICS
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	PERLPATH=${PERL5}
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run makeinfo pkg-config
INFO_FILES=		yes
REPLACE_PERL=		texi2man

INSTALLATION_DIRS+=	share/examples/xboard
CONF_FILES+=		${PREFIX}/share/examples/xboard/xboard.conf \
			${PKG_SYSCONFDIR}/xboard.conf

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

DEPENDS+=		gnuchess-[0-9]*:../../games/gnuchess

SUBST_CLASSES+=		engine
SUBST_MESSAGE.engine=	Setting gnuchess as default chess engine.
SUBST_STAGE.engine=	pre-configure
SUBST_FILES.engine=	xboard.conf
SUBST_SED.engine=	-e '/ChessProgram / s,fairymax,gnuchess,'

SUBST_CLASSES+=			wavplayer
SUBST_MESSAGE.wavplayer=	Setting wav player location.
SUBST_STAGE.wavplayer=		post-build
SUBST_FILES.wavplayer=		xboard.conf
SUBST_SED.wavplayer=		-e 's,aplay -q,${WAVPLAYER},g'

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
WAVPLAYER=      /usr/bin/audioplay
.elif ${OPSYS} == "OpenBSD"
WAVPLAYER=      /usr/bin/aucat -i
.elif ${OPSYS} == "Darwin"
WAVPLAYER=      ${PREFIX}/bin/qtplay
DEPENDS+=       qtplay-[0-9]*:../../audio/qtplay
.elif ${OPSYS} == "Linux"
WAVPLAYER=      ${PREFIX}/bin/aplay -q
DEPENDS+=       alsa-utils-[0-9]*:../../audio/alsa-utils
.else
CHECK_BUILTIN.oss:=     yes
.  include "../../mk/oss.builtin.mk"
CHECK_BUILTIN.oss:=     no
.  if defined(IS_BUILTIN.oss) && !empty(IS_BUILTIN.oss:M[yY][eE][sS])
WAVPLAYER=      ${PREFIX}/bin/sndfile-play
DEPENDS+=       libsndfile-[0-9]*:../../audio/libsndfile
#.  else # most crossplatform, but a bit too many dependencies
#WAVPLAYER=     ${PREFIX}/bin/playsound
#DEPENDS+=      SDL_sound-[0-9]*:../../audio/SDL_sound
.  endif
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cmail ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xboard.conf ${DESTDIR}${PREFIX}/share/examples/xboard

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
