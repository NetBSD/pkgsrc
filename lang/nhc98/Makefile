# $NetBSD: Makefile,v 1.2 2001/01/22 12:39:39 jtb Exp $

DISTNAME=		nhc98src-1.00
PKGNAME=		nhc98-1.00
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.york.ac.uk/pub/haskell/nhc98/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.cs.york.ac.uk/fp/nhc98/

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
