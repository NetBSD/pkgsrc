# $NetBSD: Makefile,v 1.9 2018/09/06 08:23:08 nia Exp $

DISTNAME=	retroarch-${RETROARCH_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	RetroArch
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.retroarch.com/
COMMENT=	Official reference frontend for the libretro API
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-builtinminiupnpc
CONFIGURE_ARGS+=	--disable-builtinzlib
CONFIGURE_ARGS+=	--disable-builtinflac
CONFIGURE_ARGS+=	--disable-discord

CONFIGURE_ENV+=	BIN_DIR=${PREFIX}/bin
CONFIGURE_ENV+=	MAN_DIR=${PREFIX}/${PKGMANDIR}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

DEPENDS+=	libretro-database>=${PKGVERSION_NOREV}:../../emulators/libretro-database
DEPENDS+=	libretro-core-info>=${PKGVERSION_NOREV}:../../emulators/libretro-core-info

CPPFLAGS+=	-DPREFIX=\"${PREFIX}\"

.include "../../mk/bsd.fast.prefs.mk"

# On exit (load a game first):
# assertion "pthread__tsd_destructors[key] != NULL" failed:
# file "/usr/src/lib/libpthread/pthread_tsd.c", line 287, function "pthread_key_delete"
# [1]   Abort trap (core dumped) retroarch
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-thread_storage
.endif

.include "version.mk"
.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
