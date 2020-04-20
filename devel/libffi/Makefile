# $NetBSD: Makefile,v 1.41 2020/04/20 10:00:54 dsainty Exp $

DISTNAME=	libffi-3.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.sourceware.org/libffi/
COMMENT=	Foreign function interface
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_TOOLS.SunOS+=	perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-multi-os-directory
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include
PKGCONFIG_OVERRIDE+=	libffi.pc.in
INFO_FILES=		yes
TEST_DEPENDS+=		dejagnu-[0-9]*:../../devel/dejagnu
TEST_TARGET=		check

.include "../../mk/compiler.mk"
# The Compaq C frontend groks .s, but not .S. Assemble osf.S directly w/ as(1).
pre-build:
.if !empty(PKGSRC_COMPILER:Mccc)
	cd ${WRKSRC} && ./libtool --mode=compile --tag=CC as -I. -Iinclude -o src/alpha/osf.lo -c src/alpha/osf.S
.endif

.include "../../mk/bsd.prefs.mk"

# patch-src_m68k_ffi.c uses m68k_sync_icache(2)
.if !empty(MACHINE_PLATFORM:MNetBSD-*-m68k)
LIBS+=		-lm68k
.endif

# fix http://gnats.netbsd.org/42865
.if !empty(MACHINE_PLATFORM:MSunOS-*-i386) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS+=	-D__PIC__
.endif

# Irix fixes from PR 48587, but also ensures compatibility with other shells.
# Ksh also has difficulty parsing the shell scripts patched as part of this PR.
USE_TOOLS+=		bash:build
MAKE_FLAGS+=		SHELL=${TOOLS_DIR}/bin/bash

# On platforms where ld(1) is LLVM ld, relocations against read-only
# segments has to be explicitly allowed.
.if !empty(MACHINE_PLATFORM:MFreeBSD-1[2-9].*-*)
CFLAGS+=	-Wl,-z,notext
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
