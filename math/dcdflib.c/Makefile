# $NetBSD: Makefile,v 1.2 2001/02/08 06:01:05 jtb Exp $

DISTNAME=		dcdflib.c-1.1
CATEGORIES=		math
MASTER_SITES=		ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://odin.mdacc.tmc.edu/anonftp/page_2.html

WRKSRC=			${WRKDIR}/dcdflib.c/src

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.c
	@for f in README doc/dcdflib.chs doc/dcdflib.fdoc; do			    \
	i="${INSTALL_DATA} ${WRKDIR}/dcdflib.c/$$f ${PREFIX}/share/doc/dcdflib.c/"; \
	${ECHO} $$i; $$i;							    \
	done

.include "../../mk/bsd.pkg.mk"
