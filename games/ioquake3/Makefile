# $NetBSD: Makefile,v 1.23 2022/08/11 05:08:27 gutteridge Exp $
#

DISTNAME=	ioquake3-1.36.20200125
PKGREVISION=	12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ioquake/}
GITHUB_PROJECT=	ioq3
GITHUB_TAG=	daae32ddfdab2172a628072ed3ff7dd1fc1563fe

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ioquake3.org/
COMMENT=	Open source Quake 3 distribution
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	release
INSTALL_TARGET=	copyfiles

MAKE_FLAGS+=	COPYDIR=${DESTDIR}${PREFIX}/lib/ioquake3
MAKE_FLAGS+=	PKG_CONFIG=${TOOLS_PATH.pkg-config:Q}
MAKE_FLAGS+=	USE_INTERNAL_JPEG=0
MAKE_FLAGS+=	USE_INTERNAL_OGG=0
MAKE_FLAGS+=	USE_INTERNAL_OPUS=0
MAKE_FLAGS+=	USE_INTERNAL_VORBIS=0
MAKE_FLAGS+=	USE_INTERNAL_ZLIB=0

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
QUAKE_ARCH=	arm
.elif !empty(MACHINE_ARCH:M*mips*)
QUAKE_ARCH=	mips
.elif !empty(MACHINE_ARCH:M*sh3*)
QUAKE_ARCH=	sh
.elif ${MACHINE_ARCH} == "i386"
QUAKE_ARCH=	x86
.elif ${MACHINE_ARCH} == "powerpc"
QUAKE_ARCH=	ppc
.elif ${MACHINE_ARCH} == "powerpc64"
QUAKE_ARCH=	ppc64
.elif ${MACHINE_ARCH} == "sparc64"
QUAKE_ARCH=	sparc
.else
QUAKE_ARCH=	${MACHINE_ARCH}
.endif

MAKE_FLAGS+=	COMPILE_ARCH=${QUAKE_ARCH:Q}

PLIST_SUBST+=	QUAKE_ARCH=${QUAKE_ARCH:Q}

# recursive error after: VM_CompileX86: mprotect failed
NOT_PAX_MPROTECT_SAFE+=	lib/ioquake3/ioq3ded.${QUAKE_ARCH}
NOT_PAX_MPROTECT_SAFE+=	lib/ioquake3/ioquake3.${QUAKE_ARCH}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man6
INSTALLATION_DIRS+=	lib/ioquake3

post-install:
.for prog in ioquake3 ioq3ded
	${LN} -sf ${DESTDIR}${PREFIX}/lib/ioquake3/${prog}.${QUAKE_ARCH} \
	    ${DESTDIR}${PREFIX}/bin/${prog}
	${INSTALL_MAN} ${FILESDIR}/${prog}.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
.endfor

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
