# $NetBSD: Makefile,v 1.66 2013/02/01 11:26:22 hans Exp $

DISTNAME=	gmp-5.1.0
CATEGORIES=	devel math
MASTER_SITES=	ftp://ftp.gmplib.org/pub/${DISTNAME}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmplib.org/
COMMENT=	Library for arbitrary precision arithmetic
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INFO_FILES=		yes
USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 autoconf makeinfo
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-readline

TEST_TARGET=		check

PLIST_VARS+=		cxx

.include "../../mk/bsd.prefs.mk"

.if empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ARGS+=	--enable-cxx
PLIST.cxx=		yes
.endif

.if !empty(MACHINE_PLATFORM:MIRIX-5*) && !empty(ABI)
ABI=			o32
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
# The configure script thinks gcc 2.95 for ARM is too buggy to use.
GCC_REQD+=		3.0
.endif

.if ${MACHINE_ARCH} == "i386"
# XXX SunOS should work, but currently bombs in mpn/fat.c
.  if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS" || !empty(PKGSRC_COMPILER:Msunpro)
# don't use x86 assembly (it doesn't build)
CONFIGURE_ENV+=		MPN_PATH="generic"
.  else
PKG_OPTIONS_VAR=	PKG_OPTIONS.gmp
PKG_SUPPORTED_OPTIONS=	gmp-fat mmx simd
PKG_SUGGESTED_OPTIONS=	gmp-fat
.    include "../../mk/bsd.options.mk"
###
### Support for a "fat" binary on i386.  There's CPU autodetection,
### so we'll be safe and filter out -march/-mcpu, et. al.
###
### XXX	Currently, the 'mmx' and 'simd' options imply the same thing,
###	as cpu detection is done at runtime.  Is there a more elegant
###	way to handle this?
###
.    if empty(PKG_OPTIONS:Mgmp-fat) &&	\
        (!empty(PKG_OPTIONS:Mmmx) || !empty(PKG_OPTIONS:Msimd))
PKG_OPTIONS+=	gmp-fat
.    endif
.    if !empty(PKG_OPTIONS:Mgmp-fat)
CONFIGURE_ARGS+=	--enable-fat
BUILDLINK_TRANSFORM+=	rm-optarg:-march rm-optarg:-mcpu
BUILDLINK_TRANSFORM+=	rm:-mmmx rm:-msse rm:-msse2 rm:-msse3 rm:-m3dnow
.    endif
.  endif
.endif

pre-configure:
	cd ${WRKSRC} && type autoconf && autoconf

.include "../../mk/bsd.pkg.mk"
