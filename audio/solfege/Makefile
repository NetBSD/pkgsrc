# $NetBSD: Makefile,v 1.75 2020/06/02 08:23:14 adam Exp $

DISTNAME=		solfege-3.22.2
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNU:=solfege/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/solfege/
COMMENT=		Practice several musical ear training exercises
LICENSE=		gnu-gpl-v3

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		txt2man-[0-9]*:../../converters/txt2man

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q} ac_cv_path_MSGGREP=true
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-oss-sound
CONFIGURE_ARGS+=	--disable-pygtk-test
CONFIGURE_ARGS+=	--enable-docbook-stylesheet=${PREFIX}/share/xsl/docbook/html/chunk.xsl
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

USE_TOOLS+=		gmake gm4 makeinfo pkg-config msgfmt bash:run

REPLACE_BASH=		lesson-files/bin/csound-play-harmonic-interval.sh

REPLACE_PYTHON=	*.py *.py.in */*.py */*.py.in
PYTHON_VERSIONS_ACCEPTED= 27 # py-gtk2

SUBST_CLASSES+=		sound
SUBST_STAGE.sound=	do-configure
SUBST_FILES.sound=	default.config
SUBST_VARS.sound=	WAVPLAYER
SUBST_VARS.sound+=	MIDIPLAYER
SUBST_VARS.sound+=	MP3PLAYER
SUBST_VARS.sound+=	OGGPLAYER
SUBST_MESSAGE.sound=	Setting default audio player.

EGDIR=			${PREFIX}/share/examples/solfege
CONF_FILES+=		${EGDIR}/solfege ${PKG_SYSCONFDIR}/solfege
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
WAVPLAYER=	/usr/bin/audioplay
MIDIPLAYER=	/usr/bin/midiplay
MP3PLAYER=	${PREFIX}/bin/mpg123
OGGPLAYER=	${PREFIX}/bin/ogg123
.elif ${OPSYS} == "Darwin"
WAVPLAYER=	${PREFIX}/bin/qtplay
MIDIPLAYER=	${PREFIX}/bin/qtplay
MP3PLAYER=	${PREFIX}/bin/qtplay
OGGPLAYER=	${PREFIX}/bin/qtplay
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
