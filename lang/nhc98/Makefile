# $NetBSD: Makefile,v 1.6 2001/02/24 22:51:03 jtb Exp $

DISTNAME=		nhc98src-1.02
PKGNAME=		nhc98-1.02
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines

NOT_FOR_PLATFORM=	*-*-alpha

WRKSRC=			${WRKDIR}/nhc98-1.02

HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

# Note that you can also build with ghc (Glasgow Haskell Compiler).

USE_GMAKE=		#defined
ALL_TARGET=		all-gcc

HARCH=			`${WRKSRC}/script/harch`
PLIST_SUBST+=		HARCH=${HARCH}

do-build:
	cd ${WRKSRC} && ${GMAKE}

pre-install:
	${RM} -fr ${WRKSRC}/docs/CVS ${WRKSRC}/docs/*/CVS

.include "../../mk/bsd.pkg.mk"
