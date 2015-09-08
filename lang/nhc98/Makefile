# $NetBSD: Makefile,v 1.50 2015/09/08 11:57:50 jperkin Exp $

DISTNAME=		nhc98src-1.22
PKGNAME=		nhc98-1.22
PKGREVISION=		2
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

.include "../../mk/bsd.prefs.mk"

# These platforms cannot build 32-on-64 binaries.
NOT_FOR_PLATFORM+=	*-*-alpha
NOT_FOR_PLATFORM+=	DragonFly-*-x86_64

# This package has LP64 issues, so must build as 32-bit binary.
M32=
.for P in ${LP64PLATFORMS}
.if ${MACHINE_PLATFORM:M${P}}
M32=			-m32
.endif
.endfor
BUILD_MAKE_FLAGS+=	PKGSRC_M32=${M32}

PLIST_SUBST+=		HARCH=`${WRKSRC}/script/harch`

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
