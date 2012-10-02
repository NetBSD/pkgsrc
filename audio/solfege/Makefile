# $NetBSD: Makefile,v 1.40 2012/10/02 23:48:09 asau Exp $
#

DISTNAME=		solfege-3.14.1
PKGREVISION=		15
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=solfege/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.solfege.org/
COMMENT=		Practice several musical ear training exercises

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		txt2man-[0-9]*:../../converters/txt2man

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q} ac_cv_path_MSGGREP=true
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-oss-sound
CONFIGURE_ARGS+=	--disable-pygtk-test
CONFIGURE_ARGS+=	--enable-docbook-stylesheet=${LOCALBASE}/share/xsl/docbook/html/chunk.xsl
CONFIGURE_ARGS+=	--localedir=${LOCALBASE}/${PKGLOCALEDIR}/locale

USE_TOOLS+=		gmake gm4 makeinfo pkg-config msgfmt bash:run

REPLACE_BASH=		lesson-files/bin/csound-play-harmonic-interval.sh

PYTHON_PATCH_SCRIPTS=	*.py *.py.in */*.py */*.py.in

SUBST_CLASSES+=		sound
SUBST_STAGE.sound=	do-configure
SUBST_FILES.sound=	default.config
SUBST_SED.sound=	-e 's|@WAVPLAYER@|${WAVPLAYER}|g'
SUBST_SED.sound+=	-e 's|@MIDIPLAYER@|${MIDIPLAYER}|g'
SUBST_SED.sound+=	-e 's|@MP3PLAYER@|${MP3PLAYER}|g'
SUBST_SED.sound+=	-e 's|@OGGPLAYER@|${OGGPLAYER}|g'
SUBST_MESSAGE.sound=	Setting default audio player.

EGDIR=			${PREFIX}/share/examples/solfege
CONF_FILES+=		${EGDIR}/solfege ${PKG_SYSCONFDIR}/solfege
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
WAVPLAYER=	/usr/bin/audioplay
MIDIPLAYER=	/usr/bin/midiplay
MP3PLAYER=	${LOCALBASE}/bin/mpg123
OGGPLAYER=	${LOCALBASE}/bin/ogg123
.elif ${OPSYS} == "Darwin"
WAVPLAYER=	${LOCALBASE}/bin/qtplay
MIDIPLAYER=	${LOCALBASE}/bin/qtplay
MP3PLAYER=	${LOCALBASE}/bin/qtplay
OGGPLAYER=	${LOCALBASE}/bin/qtplay
DEPENDS+=	qtplay-[0-9]*:../../audio/qtplay
.endif

post-install:
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/share/solfege/mpd \
		${DESTDIR}${PREFIX}/share/solfege/soundcard \
		${DESTDIR}${PREFIX}/share/solfege/src

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.14
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
