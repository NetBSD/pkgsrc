# $NetBSD: Makefile,v 1.53 2008/10/09 10:56:16 wiz Exp $

DISTNAME=	gmp-4.2.4
CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_GNU:=gmp/}
EXTRACT_SUFX=	.tar.bz2

#PATCHFILES=
#PATCH_SITES+=		http://www.gmplib.org/patches/
#PATCH_DIST_STRIP=	-p0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmplib.org/
COMMENT=	Library for arbitrary precision arithmetic
#LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES=		c c++ c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 autoconf

CONFIGURE_ARGS+=	--enable-cxx --without-readline

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MIRIX-5*) && !empty(ABI)
ABI=			o32
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
# The configure script thinks gcc 2.95 for ARM is too buggy to use.
GCC_REQD+=		3.0
.endif

.if ${MACHINE_ARCH} == "i386"
.  if ${OPSYS} == "Darwin"
# don't use x86 assembly (it doesn't build)
CONFIGURE_ENV+=		MPN_PATH="generic"
.  else
PKG_OPTIONS_VAR=	PKG_OPTIONS.gmp
PKG_SUPPORTED_OPTIONS=	gmp-fat
#PKG_SUGGESTED_OPTIONS=	gmp-fat		# XXX could be good for bulk builds (?)
.    include "../../mk/bsd.options.mk"
###
### Support for a "fat" binary on i386.  There's CPU autodetection,
### so we'll be safe and filter out -march/-mcpu, et. al.
###
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
