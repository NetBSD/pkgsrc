# $NetBSD: Makefile,v 1.14 2009/06/30 00:07:14 joerg Exp $
#

DISTNAME=		silc-toolkit-0.9.13
PKGREVISION=		1
CATEGORIES=		devel chat security
MASTER_SITES=		http://www.silcnet.org/download/toolkit/sources/ \
			ftp://ftp.silcnet.org/silc/toolkit/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=		Secure Internet Live Conferencing (SILC) protocol Toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

CONFLICTS+=		silc-client<1.0.1nb1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
OVERRIDE_DIRDEPTH=	3	# */*/*/libtool

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/silc
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/silc
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silc-toolkit
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/silc/modules
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-irssi
CONFIGURE_ARGS+=	--without-silcd
CONFIGURE_ARGS+=	--without-libtoolfix

# XXX: Avoid an ICE in gcc2 on sparc64
#
CONFIGURE_ENV+=		F77=${FALSE:Q}

# lib/silcclient/client_attrs.c causes an ICE with xlc on Darwin.
NOT_FOR_COMPILER+=	xlc

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "options.mk"

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
