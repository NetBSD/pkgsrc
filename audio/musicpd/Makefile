# $NetBSD: Makefile,v 1.197 2019/10/21 21:19:35 adam Exp $

DISTNAME=		mpd-0.21.15
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
CATEGORIES=		audio
MASTER_SITES=		https://www.musicpd.org/download/mpd/0.21/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.musicpd.org/
COMMENT=		Remote controllable audio player
LICENSE=		gnu-gpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	sphinx:tool

CONFLICTS=		mpd-[0-9]*

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c99 c++14
MESON_ARGS+=		-Ddocumentation=true

# worrying libraries with limited maintainance:
# - audiofile, many CVEs, no activity since 2016
#   using sndfile instead
# - mad, no release since 2004
#   using mpg123 instead
MESON_ARGS+=		-Dmad=disabled
MESON_ARGS+=		-Daudiofile=disabled

# not available in pkgsrc?
MESON_ARGS+=		-Dnfs=disabled
MESON_ARGS+=		-Diso9660=disabled
MESON_ARGS+=		-Dsndio=disabled

# c++14
GCC_REQD+=		6

CPPFLAGS.SunOS+=	-std=gnu99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mpd
CONF_FILES=		${EGDIR}/mpd.conf ${PKG_SYSCONFDIR}/mpd.conf
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mpd.conf
SUBST_MESSAGE.paths=	Fixing path to sound device in example config.
SUBST_VARS.paths+=	DEVOSSAUDIO

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing sphinx binary name.
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build${PYVERSSUFFIX},"

LDFLAGS+=		${LIBOSSAUDIO}

INSTALLATION_DIRS=	${EGDIR}

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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
