# $NetBSD: Makefile,v 1.6 2001/11/29 01:12:40 hubertf Exp $

DISTNAME=	dcdflib.c-1.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/page_2.html
COMMENT=	Library of C Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.c/src

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.c
	cd ${WRKDIR}/dcdflib.c/ && ${INSTALL_DATA} README 		\
	doc/dcdflib.chs doc/dcdflib.fdoc ${PREFIX}/share/doc/dcdflib.c/

.include "../../mk/bsd.pkg.mk"
