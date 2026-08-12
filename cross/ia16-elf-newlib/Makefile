# $NetBSD: Makefile,v 1.1 2026/08/12 16:29:51 ryoon Exp $

DISTNAME=		newlib-ia16
PKGNAME=		ia16-elf-newlib-2.4.0pre20260617
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITLAB:=tkchia/}
GITLAB_PROJECT=		newlib-ia16
GITLAB_TAG=		8aa8f6eb7080eb94713c5b3bee4df44de1df109b

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://gitlab.com/tkchia/gcc-ia16
COMMENT=		Bootstrap GCC for IA16 ELF cross environment
LICENSE=		gnu-gpl-v3

TOOL_DEPENDS+=		ia16-elf-binutils-[0-9]*:../../cross/ia16-elf-binutils
TOOL_DEPENDS+=		ia16-elf-gcc-bootstrap-[0-9]*:../../cross/ia16-elf-gcc-bootstrap

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

WRKSRC=			${WRKDIR}/${DISTNAME}-${GITLAB_TAG}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross/ia16-elf
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo

USE_GNU_CONFIGURE_TARGET=	yes
TARGET_MACHINE_GNU_PLATFORM=	ia16-elf

# We must build this in-tree for elf2dosx command.
GNU_CONFIGURE_STRICT=	no # has sub-configures

# A different sysroot causes "exec: Unknown option -o" error from xgcc.
#CONFIGURE_ARGS+=	--with-sysroot=${GNU_CONFIGURE_PREFIX}
#CONFIGURE_ARGS+=	--with-as=${PREFIX}/cross/ia16-elf/ia16-elf/bin/as
#CONFIGURE_ARGS+=	--with-ld=${PREFIX}/cross/ia16-elf/ia16-elf/bin/ld
CONFIGURE_ARGS+=	--with-build-time-tools=${PREFIX}/cross/ia16-elf/bin
CONFIGURE_ARGS+=	--enable-newlib-elix-level=2
CONFIGURE_ARGS+=	--disable-elks-libc
CONFIGURE_ARGS+=	--disable-freestanding
CONFIGURE_ARGS+=	--disable-newlib-wide-orient
CONFIGURE_ARGS+=	--enable-newlib-nano-malloc
CONFIGURE_ARGS+=	--disable-newlib-multithread
CONFIGURE_ARGS+=	--enable-newlib-global-atexit
CONFIGURE_ARGS+=	--enable-newlib-reent-small
CONFIGURE_ARGS+=	--disable-newlib-fseek-optimization
CONFIGURE_ARGS+=	--disable-newlib-unbuf-stream-opt
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--enable-newlib-io-c99-formats
CONFIGURE_ARGS+=	--enable-newlib-mb
CONFIGURE_ARGS+=	--enable-newlib-iconv
CONFIGURE_ARGS+=	--enable-newlib-iconv-encodings=utf_8,utf_16,cp850,cp852,koi8_uni

CONFIGURE_ENV+=		AR_FOR_TARGET=${PREFIX}/cross/ia16-elf/bin/ia16-elf-ar
CONFIGURE_ENV+=		CC_FOR_TARGET=${PREFIX}/cross/ia16-elf-bootstrap/bin/ia16-elf-gcc
CONFIGURE_ENV+=		RANLIB_FOR_TARGET=${PREFIX}/cross/ia16-elf-bootstrap/bin/ia16-elf-ranlib
CONFIGURE_ENV+=		STRIP_FOR_TARGET=${PREFIX}/cross/ia16-elf-bootstrap/bin/ia16-elf-strip

pre-configure:
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
