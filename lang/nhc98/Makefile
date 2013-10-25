# $NetBSD: Makefile,v 1.45 2013/10/25 06:25:18 dholland Exp $

DISTNAME=		nhc98src-1.22
PKGNAME=		nhc98-1.22
CATEGORIES=		lang
MASTER_SITES=		http://www.haskell.org/nhc98/

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.haskell.org/nhc98/
COMMENT=		Portable Haskell 98 compiler

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_JOBS_SAFE=		no
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98
BUILD_TARGET=		all

.if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "amd64") || \
    (${MACHINE_ARCH} == "sparc64") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "powerpc64") || (defined(ABI) && ${ABI} == "64")
# 64-bit platform
BUILD_MAKE_FLAGS+=	PKGSRC_M32=-m32
.else
# not a 64-bit platform
BUILD_MAKE_FLAGS+=	PKGSRC_M32=
.endif

PLIST_SUBST+=		HARCH=`${WRKSRC}/script/harch`

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
