# $NetBSD: Makefile,v 1.1.1.1 2001/01/29 06:13:54 jtb Exp $

DISTNAME=		dcdflib.c-1.1
CATEGORIES=		math
MASTER_SITES=		ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://odin.mdacc.tmc.edu/anonftp/page_2.html

USE_LIBTOOL=		YES
WRKSRC=			${WRKDIR}/dcdflib.c/src

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.c
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dcdflib.c
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.chs ${PREFIX}/share/doc/dcdflib.c
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.fdoc ${PREFIX}/share/doc/dcdflib.c

.include "../../mk/bsd.pkg.mk"
