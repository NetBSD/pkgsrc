# $NetBSD: Makefile,v 1.87 2023/01/16 19:45:27 schmonz Exp $

DISTNAME=		solfege-3.23.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=solfege/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/solfege/
COMMENT=		Practice several musical ear training exercises
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		lilypond-[0-9]*:../../print/lilypond
BUILD_DEPENDS+=		txt2man-[0-9]*:../../converters/txt2man

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q} ac_cv_path_MSGGREP=true
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-oss-sound
CONFIGURE_ARGS+=	--enable-docbook-stylesheet=${PREFIX}/share/xsl/docbook/html/chunk.xsl
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

USE_TOOLS+=		gmake gm4 makeinfo pkg-config msgfmt bash:run

REPLACE_BASH=		exercises/standard/lesson-files/bin/csound-play-harmonic-interval.sh

REPLACE_PYTHON=	*.py */*.py */*/*.py *.py.in */*.py.in */*/*.py.in
PYTHON_VERSIONS_INCOMPATIBLE= 27

SUBST_CLASSES+=		sound
SUBST_STAGE.sound=	do-configure
SUBST_FILES.sound=	default.config
SUBST_VARS.sound=	WAVPLAYER
SUBST_VARS.sound+=	MIDIPLAYER
SUBST_VARS.sound+=	MP3PLAYER
SUBST_VARS.sound+=	OGGPLAYER
SUBST_MESSAGE.sound=	Setting default audio players.

SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	do-configure
SUBST_FILES.sysconfdir=	run-solfege.py
SUBST_VARS.sysconfdir=	PKG_SYSCONFDIR

PKG_SYSCONFSUBDIR=	solfege

BUILD_TARGET=		genfiles

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
WAVPLAYER=	/usr/bin/afplay
DEPENDS+=	timidity-[0-9]*:../../audio/timidity
MIDIPLAYER=	${PREFIX}/bin/timidity
MP3PLAYER=	/usr/bin/afplay
OGGPLAYER=	${PREFIX}/bin/ogg123
.endif

post-install:
	find ${DESTDIR}${PREFIX} -type d -name __pycache__ | xargs rm -rf

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
