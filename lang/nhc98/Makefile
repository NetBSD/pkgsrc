# $NetBSD: Makefile,v 1.1.1.1 2000/11/29 00:33:09 jtb Exp $

DISTNAME=		nhc98src-1.00
PKGNAME=		nhc98-1.00
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}/nhc98-1.00
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${PREFIX} \
			+docs --docdir=${PREFIX}/share/doc/nhc98

# Note that you can also build with ghc (Glasgow Haskell Compiler).

USE_GMAKE=		YES

post-extract:
	@for f in `${FIND} ${WRKSRC}/docs -type d | ${GREP} CVS`; do \
	${RM} -R $$f ; done
	${RMDIR} ${WRKSRC}/docs/hat

do-build:
	@(cd ${WRKSRC} && ${GMAKE})

.include "../../mk/bsd.pkg.mk"
