# $NetBSD: Makefile,v 1.5 2001/02/19 17:08:12 jtb Exp $

DISTNAME=		nhc98src-1.00
PKGNAME=		nhc98-1.00
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/
COMMENT=		Portable Haskell 98 compiler

NOT_FOR_PLATFORM=	*-*-alpha

WRKSRC=			${WRKDIR}/nhc98-1.00
HAS_CONFIGURE=		#defined
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

# Note that you can also build with ghc (Glasgow Haskell Compiler).

USE_GMAKE=		#defined

HARCH=			`${WRKSRC}/script/harch`
PLIST_SUBST+=		HARCH=${HARCH}

post-extract:
	${RM} -fr ${WRKSRC}/docs/CVS ${WRKSRC}/docs/*/CVS
	${RMDIR} ${WRKSRC}/docs/hat

do-build:
	cd ${WRKSRC} && ${GMAKE}

.include "../../mk/bsd.pkg.mk"
