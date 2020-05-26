# $NetBSD: Makefile,v 1.6 2020/05/26 09:45:16 nia Exp $

DISTNAME=	libretro-reicast-20190508
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	reicast-emulator
GITHUB_TAG=	8c38fcedbe064f7fbda9c2213fd6987b7d4e4dbc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/reicast/
COMMENT=	Libretro core based on the Reicast Sega Dreamcast emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++11

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

MAKE_FLAGS+=	platform=unix
MAKE_FLAGS+=	HAVE_OPENMP=0
MAKE_FLAGS+=	HAVE_LTCG=0
MAKE_FLAGS+=	SINGLE_PREC_FLAGS=1
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"
MAKE_FLAGS+=	CC_AS=${AS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	WITH_DYNAREC=x86_64
.elif ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	WITH_DYNAREC=x86
.elif ${MACHINE_ARCH} == "aarch64"
MAKE_FLAGS+=	WITH_DYNAREC=arm64
.elif !empty(MACHINE_ARCH:M*arm*)
CFLAGS+=	-marm
MAKE_FLAGS+=	WITH_DYNAREC=arm
.elif !empty(MACHINE_ARCH:M*mips*)
MAKE_FLAGS+=	WITH_DYNAREC=mips
.else
MAKE_FLAGS+=	WITH_DYNAREC=
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/reicast_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/reicast_libretro.so

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
