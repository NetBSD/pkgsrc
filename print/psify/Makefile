# $NetBSD: Makefile,v 1.5.4.1 2004/07/15 19:26:46 agc Exp $
#

DISTNAME=	psify-19980216
CATEGORIES=	print
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	Makefile psify.c psify.lex psify.man

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://www.mit.edu/afs/athena/system/pmax_ul4/srvd.74/usr/sipb/src/psify/
COMMENT=	Pretty print C, CLU, SCHEME, Java and ARGUS source files

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	psify
EXTRACT_ONLY=	#empty

NO_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	lex

INSTALL_TARGET=	install prefix=${PREFIX}

post-extract:
	@for i in ${DISTFILES}; \
	do \
	    ${CP} ${_DISTDIR}/$$i ${WRKSRC}; \
	done

.include "../../mk/bsd.pkg.mk"
