# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:16 jmmv Exp $
#

DISTNAME=	psify-19980216
WRKSRC=		${WRKDIR}
CATEGORIES=	print
MASTER_SITES=	${HOMEPAGE}
DISTFILES=	Makefile psify.c psify.lex psify.man

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://www.mit.edu/afs/athena/system/pmax_ul4/srvd.74/usr/sipb/src/psify/
COMMENT=	Pretty print C, CLU, SCHEME, Java and ARGUS source files

DIST_SUBDIR=	psify
EXTRACT_ONLY=	#empty
NO_CONFIGURE=	yes

INSTALL_TARGET=	install prefix=${PREFIX}

post-extract:
	@for i in ${DISTFILES}; \
	do \
	    ${CP} ${_DISTDIR}/$$i ${WRKSRC}; \
	done

.include "../../mk/bsd.pkg.mk"
