# $NetBSD: Makefile,v 1.12 2002/01/03 13:52:48 wiz Exp $

DISTNAME=		nhc98src-1.06
PKGNAME=		nhc98-1.06
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64

# KEY_RESIZE
USE_NCURSES=		YES

WRKSRC=			${WRKDIR}/${PKGNAME}

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		CC=gcc
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

# Note that you can also build with ghc (Glasgow Haskell Compiler) or
# hbc (Chalmers Haskell).

USE_GMAKE=		yes
USE_JAVA=		yes

ALL_TARGET=		default

HARCH=			`${WRKSRC}/script/harch`
PLIST_SUBST+=		HARCH=${HARCH}

post-extract:
	@${FIND} ${WRKSRC}/docs -type d -name \*CVS\* | ${XARGS} ${RM} -rf

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
