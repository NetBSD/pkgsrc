# $NetBSD: Makefile,v 1.9 2009/02/21 15:51:35 asau Exp $
#

DISTNAME=	libffi-3.0.8
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/libffi/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://sources.redhat.com/libffi/
COMMENT=	Foreign function interface

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
INFO_FILES=	# PLIST

PKGCONFIG_OVERRIDE+=	libffi.pc.in

# Since we don't have "TEST_DEPENDS", we implement it as a hack:
.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=	check
BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu
.endif

.include "../../mk/bsd.pkg.mk"
