# $NetBSD: Makefile,v 1.34 2024/05/16 06:14:54 wiz Exp $
#

DISTNAME=	ioquake3-1.36.20200125
PKGREVISION=	22
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
MAKE_FLAGS+=	USE_INTERNAL_LIBS=0
MAKE_FLAGS+=	USE_OPENAL=0
MAKE_FLAGS+=	USE_RENDERER_DLOPEN=0

# causes hang on game exit, needs investigating...
MAKE_FLAGS+=	USE_VOIP=0

# build only the original renderer for now
MAKE_FLAGS+=	BUILD_RENDERER_OPENGL2=0

.include "arch.mk"

MAKE_FLAGS+=	COMPILE_ARCH=${QUAKE_ARCH:Q}

.if ${SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	SO_EXT="dylib"
.else
PLIST_SUBST+=	SO_EXT="so"
.endif

.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100700
MAKE_FLAGS+=	MACOSX_VERSION_MIN=10.4
.endif

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

.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
