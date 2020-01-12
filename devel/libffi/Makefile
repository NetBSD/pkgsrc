# $NetBSD: Makefile,v 1.34 2020/01/12 10:48:50 pho Exp $

DISTNAME=	libffi-3.2.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.sourceware.org/libffi/
COMMENT=	Foreign function interface
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--includedir=${PREFIX}/include
PKGCONFIG_OVERRIDE+=	libffi.pc.in
INFO_FILES=		yes

.include "../../mk/compiler.mk"
# The Compaq C frontend groks .s, but not .S. Assemble osf.S directly w/ as(1).
pre-build:
.if !empty(PKGSRC_COMPILER:Mccc)
	cd ${WRKSRC} && ./libtool --mode=compile --tag=CC as -I. -Iinclude -o src/alpha/osf.lo -c src/alpha/osf.S
.endif

# Since we don't have "TEST_DEPENDS", we implement it as a hack:
.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=	check
TEST_ENV=	# empty?
BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu
.endif

# patch-aj uses m68k_sync_icache(2)
.if !empty(MACHINE_PLATFORM:MNetBSD-*-m68k)
LIBS+=		-lm68k
.endif

# fix http://gnats.netbsd.org/42865
.if !empty(MACHINE_PLATFORM:MSunOS-*-i386) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS+=	-D__PIC__
.endif

# irix fixes from PR 48587
.if !empty(OPSYS:MIRIX)
USE_TOOLS+=		bash gmake
MAKE_FLAGS+=		SHELL=${TOOLS_DIR}/bin/bash
.endif

# On platforms where ld(1) is LLVM ld, relocations against read-only
# segments has to be explicitly allowed.
.if !empty(MACHINE_PLATFORM:MFreeBSD-1[2-9].*-*)
CFLAGS+=	-Wl,-z,notext
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
