# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:33 tv Exp $
#

DISTNAME=		silc-toolkit-0.9.12
PKGREVISION=		1
CATEGORIES=		devel chat security
MASTER_SITES=		http://www.silcnet.org/download/toolkit/sources/ \
			ftp://ftp.silcnet.org/silc/toolkit/sources/ \
			http://www.fi.silcnet.org/download/toolkit/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/toolkit/sources/ \
			http://www.at.silcnet.org/download/toolkit/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Secure Internet Live Conferencing (SILC) protocol Toolkit

CONFLICTS+=		silc-client<1.0.1nb1

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	libtool */*/*/libtool

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/silc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/silc
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/silc-toolkit
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/silc/modules
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-irssi
CONFIGURE_ARGS+=	--without-silcd
CONFIGURE_ARGS+=	--without-libtoolfix

# XXX: Avoid an ICE in gcc2 on sparc64
#
CONFIGURE_ENV+=		F77=${FALSE}

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# If you want to build debugging version of libraries in silc-toolkit,
# uncomment the line below.
#
#CONFIGURE_ARGS+=       --enable-debug

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../mk/bsd.pkg.mk"
