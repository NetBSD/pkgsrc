# $NetBSD: Makefile,v 1.43 2007/10/21 04:48:15 dsainty Exp $

DISTNAME=	pcre-7.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/ \
		${MASTER_SITE_SOURCEFORGE:=pcre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-utf8

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Fixing rpath output in pcre-config
SUBST_FILES.rpath=	pcre-config.in
SUBST_VARS.rpath=	COMPILER_RPATH_FLAG

PKGCONFIG_OVERRIDE=	libpcre.pc.in libpcrecpp.pc.in

# needs a stacksize of 4mb, default is 2mb
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MHPUX-11.11-*)
CONFIGURE_ENV+=		ac_cv_func_strtoll=yes
CPPFLAGS+=		-Dstrtoll=__strtoll
.endif

.include "../../mk/bsd.pkg.mk"
