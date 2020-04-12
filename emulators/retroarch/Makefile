# $NetBSD: Makefile,v 1.32 2020/04/12 08:28:37 adam Exp $

PKGNAME=	retroarch-${RETROARCH_VERSION}
DISTNAME=	RetroArch-${RETROARCH_VERSION}
PKGREVISION=	11
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/RetroArch/releases/download/v${RETROARCH_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.retroarch.com/
COMMENT=	Official reference frontend for the libretro API
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

HAS_CONFIGURE=	yes

# Needed for certain cores, e.g. Dolphin, Reicast.
NOT_PAX_MPROTECT_SAFE+=	bin/retroarch

CONFIGURE_ARGS+=	--disable-builtinmbedtls
CONFIGURE_ARGS+=	--disable-builtinminiupnpc
CONFIGURE_ARGS+=	--disable-builtinzlib
CONFIGURE_ARGS+=	--disable-builtinflac
CONFIGURE_ARGS+=	--disable-discord
CONFIGURE_ARGS+=	--disable-wayland

# necessity for loading cores, might as well fail early without it
CONFIGURE_ARGS+=	--enable-dylib

CONFIGURE_ENV+=	BIN_DIR=${PREFIX}/bin
CONFIGURE_ENV+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

DEPENDS+=	libretro-core-info>=${RETROARCH_VERSION}:../../emulators/libretro-core-info
DEPENDS+=	libretro-database>=0:../../emulators/libretro-database

CPPFLAGS+=	-DPREFIX=\"${PREFIX}\"
LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
# On exit (load a game first):
# assertion "pthread__tsd_destructors[key] != NULL" failed:
# file "/usr/src/lib/libpthread/pthread_tsd.c", line 287, function "pthread_key_delete"
# [1]   Abort trap (core dumped) retroarch
CONFIGURE_ARGS+=	--disable-thread_storage
# doesn't work yet
CONFIGURE_ARGS+=	--disable-kms
.endif

.include "version.mk"
.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
