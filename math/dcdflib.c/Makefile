# $NetBSD: Makefile,v 1.3 2001/02/17 18:22:18 wiz Exp $

DISTNAME=		dcdflib.c-1.1
CATEGORIES=		math
MASTER_SITES=		ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://odin.mdacc.tmc.edu/anonftp/page_2.html
COMMENT=		Library of C Routines for Cumulative Distribution Functions

WRKSRC=			${WRKDIR}/dcdflib.c/src

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.c
	@for f in README doc/dcdflib.chs doc/dcdflib.fdoc; do			    \
	i="${INSTALL_DATA} ${WRKDIR}/dcdflib.c/$$f ${PREFIX}/share/doc/dcdflib.c/"; \
	${ECHO} $$i; $$i;							    \
	done

.include "../../mk/bsd.pkg.mk"
