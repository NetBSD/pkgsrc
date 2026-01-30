# $NetBSD: Makefile,v 1.339 2026/01/30 08:58:13 wiz Exp $

DISTNAME=	mpd-0.24.8
PKGNAME=	${DISTNAME:S/mpd/musicpd/}
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/mpd/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.musicpd.org/
COMMENT=	Remote controllable audio player
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=9.0.0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme>=0:../../textproc/py-sphinx-rtd-theme

CONFLICTS=	mpd-[0-9]*

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++20

MESON_ARGS+=	-Ddocumentation=enabled

# worrying libraries with limited maintainance:
# - audiofile, many CVEs, no activity since 2016
#   prefer ffmpeg instead
# - mad, no release since 2004
#   prefer mpg123 instead
MESON_ARGS+=	-Daudiofile=disabled
MESON_ARGS+=	-Dmad=disabled

# not available in pkgsrc?
MESON_ARGS+=	-Dnfs=disabled
MESON_ARGS+=	-Diso9660=disabled

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

SUBST_CLASSES+=		timidity
SUBST_STAGE.timidity=	pre-configure
SUBST_MESSAGE.timidity=	Correcting the path to the timidity config file.
SUBST_FILES.timidity+=	doc/plugins.rst
SUBST_FILES.timidity+=	src/decoder/plugins/WildmidiDecoderPlugin.cxx
SUBST_SED.timidity+=	-e "s,/etc/timidity,${PKG_SYSCONFDIR},g"

EGDIR=		${PREFIX}/share/examples/mpd
CONF_FILES+=	${EGDIR}/mpd.conf ${PKG_SYSCONFDIR}/mpd.conf
CONF_FILES+=	${EGDIR}/logrotate.d/mpd ${PKG_SYSCONFDIR}/logrotate.d/mpd
RCD_SCRIPTS=	mpd
MAKE_DIRS+=	${PKG_SYSCONFDIR}/logrotate.d

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

LDFLAGS.SunOS+=		-lnsl -lsocket -licuuc
CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	mpd.conf
SUBST_MESSAGE.conf=	Setting variables in the configuration file.
SUBST_VARS.conf+=	VARBASE
SUBST_VARS.conf+=	MPD_USER

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing sphinx binary name.
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build-${PYVERSSUFFIX},"

SUBST_CLASSES+=		doc
SUBST_STAGE.doc=	pre-configure
SUBST_FILES.doc=	doc/mpd.conf.5.rst
SUBST_MESSAGE.doc=	Fixing sysconfdir path in mpd.conf location.
SUBST_VARS.doc+=	PKG_SYSCONFDIR

INSTALLATION_DIRS=	${EGDIR} ${EGDIR}/logrotate.d

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

post-extract:
	${CP} ${FILESDIR}/mpd.conf ${WRKSRC}/mpd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/mpd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpdconf.example ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/mpd.logrotate ${DESTDIR}${EGDIR}/logrotate.d/mpd

.include "../../lang/python/pyversion.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.flac+=	flac>=1.2
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
BUILDLINK_API_DEPENDS.fmtlib+=	fmtlib>=9
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
