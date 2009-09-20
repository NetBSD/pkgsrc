# $NetBSD: Makefile,v 1.12 2009/09/20 13:10:30 tnn Exp $
#

DISTNAME=	libffi-3.0.8
PKGREVISION=	2
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
	cd ${WRKSRC} && ./libtool --mode=compile --tag=CC as -I. -Iinclude -o src/alpha/osf.o -c src/alpha/osf.S
.endif

# Since we don't have "TEST_DEPENDS", we implement it as a hack:
.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=	check
BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu
.endif

.include "../../mk/bsd.pkg.mk"
