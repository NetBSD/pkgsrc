# $NetBSD: Makefile,v 1.28 2024/05/06 08:33:49 jperkin Exp $

DISTNAME=		ocp-0.2.109
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=mywave82/}
GITHUB_PROJECT=		opencubicplayer
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://stian.cubic.org/project-ocp.php
COMMENT=		Music visualizer for tracker music (TUI version)
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo perl pkg-config
USE_LANGUAGES=		c c++

DISTINFO_FILE=		${.CURDIR}/../../audio/ocp/distinfo
PATCHDIR=		${.CURDIR}/../../audio/ocp/patches

USE_CXX_FEATURES+=	c++17

INFO_FILES=		yes

TOOL_DEPENDS+=		xa65-[0-9]*:../../devel/xa65

REPLACE_SH=		ocp-curses ocp-sdl ocp-vcsa ocp-x11

# ymtype.so wants to link -llzh before it's finished building
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}

# seems fairly useless since you need curses anyway...
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--without-sdl2
CONFIGURE_ARGS+=	--without-x11

CFLAGS.SunOS+=		-mimpure-text

.include "../../mk/bsd.prefs.mk"

# curses_version(3) was introduced in NetBSD 10.0.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
.  include "../../devel/ncurses/buildlink3.mk"
.else
USE_CURSES=	wide
FAKE_NCURSES=	yes
.  include "../../mk/curses.buildlink3.mk"
.  if !${CURSES_TYPE:M*ncurses*}
CFLAGS+=	-DNCURSES_ATTR_T=int
.  endif
.endif

.include "../../mk/oss.buildlink3.mk"

PLIST_VARS+=		oss
.if ${OSS_TYPE} != "none"
PLIST.oss=		yes
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	devp/devposs.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

SUBST_CLASSES+=		ldflags
SUBST_SED.ldflags+=	-e 's/$$(SHARED_FLAGS)/$$(LDFLAGS) $$(SHARED_FLAGS)/g'
SUBST_FILES.ldflags+=	*/Makefile
SUBST_MESSAGE.ldflags=	Honoring LDFLAGS.
SUBST_STAGE.ldflags=	pre-build

.include "options.mk"
.include "../../archivers/ancient/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libdiscid/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
