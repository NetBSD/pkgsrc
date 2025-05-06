# $NetBSD: core.mk,v 1.6 2025/05/06 12:07:31 wiz Exp $

MASTER_SITES?=	${MASTER_SITE_GITHUB:=libretro/}

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"
MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	LTO=

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=	platform=osx
.  if ${MACHINE_ARCH} == "powerpc"
MAKE_FLAGS+=	arch=ppc
.  endif

CHECK_SHLIBS_SUPPORTED=	no # XXX investigate
.endif

.include "../../mk/endian.mk"

# These aren't consistent, and sometimes it's completely different
.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DBYTE_ORDER=BIG_ENDIAN
CFLAGS+=	-DWORDS_BIGENDIAN -DMSB_FIRST
.endif

# Avoid using memalign() in libco on NetBSD.
CFLAGS.NetBSD+=	-DHAVE_POSIX_MEMALIGN=1

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	lib/libretro

do-install:
	${FIND} ${WRKSRC} -name ${LIBRETRO_CORE}_libretro.${SHLIB_EXT} -exec \
	    ${INSTALL_LIB} '{}' ${DESTDIR}${PREFIX}/lib/libretro ';'

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
