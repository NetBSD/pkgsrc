# $NetBSD: Makefile,v 1.18 2012/10/31 11:19:46 asau Exp $

DISTNAME=	silc-toolkit-1.1.10
CATEGORIES=	devel chat security
MASTER_SITES=	http://www.silcnet.org/download/toolkit/sources/ \
		ftp://ftp.silcnet.org/silc/toolkit/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.silcnet.org/
COMMENT=	Secure Internet Live Conferencing (SILC) protocol Toolkit

CONFLICTS+=		silc-client<1.0.1nb1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-optimizations
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/silc
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/silc/modules
CONFIGURE_ARGS+=	--without-gmp
CONFIGURE_ARGS+=	--without-iconv
#.if ${MACHINE_ARCH} != "i386"
#CONFIGURE_ARGS+=	--disable-asm
#.endif

CONFIGURE_ENV+=		ac_cv_lib_gmp___gmpz_init=no
CONFIGURE_ENV+=		ac_cv_func_iconv=no

PKGCONFIG_OVERRIDE+=	lib/silc.pc.in
PKGCONFIG_OVERRIDE+=	lib/silcclient.pc.in
PKGCONFIG_OVERRIDE+=	lib/silcserver.pc.in

.include "../../mk/bsd.prefs.mk"

# lib/silcclient/client_attrs.c causes an ICE with xlc on Darwin.
NOT_FOR_COMPILER=	xlc

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
