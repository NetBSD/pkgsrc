# $NetBSD: Makefile,v 1.27 2004/01/27 00:53:11 heinz Exp $

DISTNAME=		nhc98src-1.16
PKGNAME=		nhc98-1.16
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=		YES
BUILDLINK_SETENV.CC=	CC=gcc

USE_NCURSES=		# KEY_RESIZE

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

# Note that you can also build with ghc (Glasgow Haskell Compiler) or
# hbc (Chalmers Haskell).

USE_GNU_TOOLS+=		make
ALL_TARGET=		default

HARCH=			`${WRKSRC}/script/harch`
PLIST_SUBST+=		HARCH=${HARCH}

post-extract:
	@${FIND} ${WRKSRC}/docs -type d -name \*CVS\* -print | ${XARGS} ${RM} -rf

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
