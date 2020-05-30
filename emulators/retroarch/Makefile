# $NetBSD: Makefile,v 1.33 2020/05/30 14:26:51 nia Exp $

.include "version.mk"

PKGNAME=	retroarch-${RETROARCH_VERSION}
CATEGORIES=	emulators

DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	retroarch.tar.gz
DISTFILES+=	retroarch-assets.tar.gz

# They are really inconsistent with publishing .tar.xz bundles...

SITES.retroarch.tar.gz= \
	-https://github.com/libretro/RetroArch/archive/v1.8.8.tar.gz

SITES.retroarch-assets.tar.gz= \
	-https://github.com/libretro/retroarch-assets/archive/ea38cbc592233095cbe9a1357932eac1ceb2a3cc.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.retroarch.com/
COMMENT=	Official reference frontend for the libretro API
LICENSE=	gnu-gpl-v3

DEPENDS+=	libretro-core-info>=${RETROARCH_VERSION}:../../emulators/libretro-core-info

WRKSRC=		${WRKDIR}/RetroArch-${RETROARCH_VERSION}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-builtinmbedtls
CONFIGURE_ARGS+=	--disable-builtinminiupnpc
CONFIGURE_ARGS+=	--disable-builtinzlib
CONFIGURE_ARGS+=	--disable-builtinflac
CONFIGURE_ARGS+=	--disable-discord
CONFIGURE_ARGS+=	--disable-glslang
CONFIGURE_ARGS+=	--disable-kms
CONFIGURE_ARGS+=	--disable-libusb
CONFIGURE_ARGS+=	--disable-opengl1
CONFIGURE_ARGS+=	--disable-plain_drm
CONFIGURE_ARGS+=	--disable-spirv_cross
CONFIGURE_ARGS+=	--disable-systemd
CONFIGURE_ARGS+=	--disable-udev
CONFIGURE_ARGS+=	--disable-update_assets
CONFIGURE_ARGS+=	--disable-update_cores
CONFIGURE_ARGS+=	--disable-v4l2
CONFIGURE_ARGS+=	--disable-vulkan
CONFIGURE_ARGS+=	--disable-wayland
CONFIGURE_ARGS+=	--disable-x11

CONFIGURE_ARGS+=	--enable-sdl2

# needed for loading cores, might as well fail early without it
CONFIGURE_ARGS+=	--enable-dylib

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "earmv6hf"
CONFIGURE_ARGS+=	--enable-floathard
.endif

.if ${MACHINE_ARCH} == "earmv7hf"
CONFIGURE_ARGS+=	--enable-floathard
CONFIGURE_ARGS+=	--enable-neon
.endif

.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--enable-sse
.endif

# On exit (load a game first):
# assertion "pthread__tsd_destructors[key] != NULL" failed:
# file "/usr/src/lib/libpthread/pthread_tsd.c", line 287, function "pthread_key_delete"
# [1]   Abort trap (core dumped) retroarch
CONFIGURE_ARGS.NetBSD+=	--disable-thread_storage

CONFIGURE_ENV+=	BIN_DIR=${PREFIX}/bin
CONFIGURE_ENV+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

CFLAGS.NetBSD+=	-D_POSIX_MONOTONIC_CLOCK

LDFLAGS.SunOS+=	-lsocket -lnsl

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing absolute paths.
SUBST_FILES.prefix=	frontend/drivers/platform_unix.c
SUBST_SED.prefix=	-e 's,"/usr/local,"${PREFIX},g'
SUBST_VARS.prefix+=	PREFIX

# Needed for certain cores, e.g. Dolphin, Reicast.
NOT_PAX_MPROTECT_SAFE+=	bin/retroarch

# Make this less slow...
CHECK_WRKREF_SKIP+=		share/retroarch/assets/*/*/*/*
CHECK_INTERPRETER_SKIP+=	share/retroarch/assets/*/*/*/*

pre-configure:
	${MKDIR} ${WRKSRC}/media/assets
	${MV} ${WRKDIR}/retroarch-assets-*/* ${WRKSRC}/media/assets

post-install:
	# deprecated stuff that isn't useful for pkgsrc
	# (we never shipped cg shaders)
	${RM} -f ${DESTDIR}${PREFIX}/bin/retroarch-cg2glsl
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/retroarch-cg2glsl.6

.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
