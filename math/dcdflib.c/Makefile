# $NetBSD: Makefile,v 1.10 2003/09/19 23:08:31 dent Exp $

DISTNAME=	dcdflib.c-1.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dcdflib.c/src
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of C Routines for Cumulative Distribution Functions

post-install:
	${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.c
	cd ${WRKDIR}/dcdflib.c/ && ${INSTALL_DATA} README 		\
	doc/dcdflib.chs doc/dcdflib.fdoc ${PREFIX}/share/doc/dcdflib.c/

.include "../../mk/bsd.pkg.mk"
