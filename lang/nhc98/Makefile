# $NetBSD: Makefile,v 1.9 2001/05/22 13:20:57 jtb Exp $

DISTNAME=		nhc98src-1.04
PKGNAME=		nhc98-1.04
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines
NOT_FOR_PLATFORM=	*-*-alpha

WRKSRC=			${WRKDIR}/${PKGNAME}

HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

# Note that you can also build with ghc (Glasgow Haskell Compiler) or
# hbc (Chalmers Haskell).

USE_GMAKE=		yes
ALL_TARGET=		basic-gcc

HARCH=			`${WRKSRC}/script/harch`
PLIST_SUBST+=		HARCH=${HARCH}

post-extract:
	${FIND} ${WRKSRC}/docs -type d -name \*CVS\* | ${XARGS} ${RM} -rf

.include "../../mk/bsd.pkg.mk"
