# $NetBSD: Makefile,v 1.21 2019/07/05 07:43:42 nia Exp $

DISTNAME=	libretro-mupen64plus-20190426
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	mupen64plus-libretro
GITHUB_TAG=	af7a4bf219ded4036257a92060b146d7d4333f0f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/mupen64plus/
COMMENT=	Libretro core based on the Mupen64Plus emulator
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		Makefile
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.if !empty(MACHINE_ARCH:M*arm*)
MAKE_FLAGS+=	WITH_DYNAREC=arm
MAKE_FLAGS+=	PIC=1
.elif ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=	WITH_DYNAREC=x86
MAKE_FLAGS+=	PIC=0
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.elif ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	WITH_DYNAREC=x86_64
MAKE_FLAGS+=	PIC=1
.elif ${MACHINE_ARCH} == "aarch64"
MAKE_FLAGS+=	WITH_DYNAREC=aarch64
MAKE_FLAGS+=	PIC=1
.else
MAKE_FLAGS+=	WITH_DYNAREC=
MAKE_FLAGS+=	DYNAREC_USED=0
MAKE_FLAGS+=	PIC=1
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./libretro/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

CFLAGS.NetBSD+=		-DHAVE_POSIX_MEMALIGN=1

.include "options.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/mupen64plus_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mupen64plus_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
