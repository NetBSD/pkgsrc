# $NetBSD: Makefile,v 1.17 2012/09/14 23:45:27 asau Exp $
#

DISTNAME=	libffi-3.0.11
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://sources.redhat.com/libffi/
COMMENT=	Foreign function interface
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	libffi.pc.in

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
TEST_ENV=	
BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu
.endif

# patch-aj uses m68k_sync_icache(2)
.if !empty(MACHINE_PLATFORM:MNetBSD-*-m68k)
LIBS+=	-lm68k
.endif

# fix http://gnats.netbsd.org/42865
.if !empty(MACHINE_PLATFORM:MSunOS-*-i386) && !empty(CC_VERSION:Mgcc-[23]*)
CPPFLAGS += -D__PIC__
.endif

.include "../../mk/bsd.pkg.mk"
