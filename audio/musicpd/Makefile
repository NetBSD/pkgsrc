# $NetBSD: Makefile,v 1.211 2020/03/20 10:23:03 nia Exp $

DISTNAME=	mpd-0.21.21
PKGNAME=	${DISTNAME:S/mpd/musicpd/}
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/mpd/0.21/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musicpd.org/
COMMENT=	Remote controllable audio player
LICENSE=	gnu-gpl-v2

CONFLICTS=	mpd-[0-9]*

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99 c++14

# c++14
GCC_REQD+=	6

MESON_ARGS+=	-Ddocumentation=true

# worrying libraries with limited maintainance:
# - audiofile, many CVEs, no activity since 2016
#   using sndfile instead
# - mad, no release since 2004
#   using mpg123 instead
MESON_ARGS+=	-Dmad=disabled
MESON_ARGS+=	-Daudiofile=disabled

# not available in pkgsrc?
MESON_ARGS+=	-Dnfs=disabled
MESON_ARGS+=	-Diso9660=disabled
MESON_ARGS+=	-Dsndio=disabled

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
MESON_ARGS+=	-Dsolaris_output=enabled
.endif

MPD_USER?=		mpd
MPD_GROUP?=		mpd
PKG_GROUPS=		${MPD_GROUP}
PKG_USERS=		${MPD_USER}:${MPD_GROUP}
PKG_GROUPS_VARS=	MPD_USER
PKG_USERS_VARS=		MPD_GROUP

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none"
MESON_ARGS+=		-Doss=disabled
.else
MESON_ARGS+=		-Doss=enabled
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/output/plugins/OssOutputPlugin.cxx
SUBST_SED.oss+=		-e "s,/dev/sound/dsp,${DEVOSSAUDIO},g"
.endif

EGDIR=		${PREFIX}/share/examples/mpd
CONF_FILES=	${EGDIR}/mpd.conf ${PKG_SYSCONFDIR}/mpd.conf
RCD_SCRIPTS=	mpd

FILES_SUBST+=	MPD_USER=${MPD_USER:Q}
FILES_SUBST+=	MPD_GROUP=${MPD_GROUP:Q}
FILES_SUBST+=	VARBASE=${VARBASE}

BUILD_DEFS+=	VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/lib/mpd \
			${MPD_USER} ${MPD_GROUP} 0755

OWN_DIRS_PERMS+=	${VARBASE}/lib/mpd/music \
			${MPD_USER} ${MPD_GROUP} 0755

OWN_DIRS_PERMS+=	${VARBASE}/lib/mpd/playlists \
			${MPD_USER} ${MPD_GROUP} 0755

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	${WRKSRC}/mpd.conf
SUBST_MESSAGE.conf=	Setting variables in the configuration file.
SUBST_VARS.conf+=	VARBASE
SUBST_VARS.conf+=	MPD_USER

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing sphinx binary name.
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build-${PYVERSSUFFIX},"

INSTALLATION_DIRS=	${EGDIR}

PYTHON_FOR_BUILD_ONLY=	tool

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:tool

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example ${DESTDIR}${EGDIR}

.include "../../devel/meson/build.mk"
BUILDLINK_ABI_DEPENDS.flac+=	flac>=1.2
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
