# $NetBSD: Makefile,v 1.1.1.1 2001/04/17 00:19:57 jtb Exp $

DISTNAME=	dcdflib.f-1.1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/page_2.html
COMMENT=	Library of Fortran Routines for Cumulative Distribution Functions

USE_FORTRAN=	yes

WRKSRC=		${WRKDIR}/dcdflib.f/src

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dcdflib.f

.include "../../mk/bsd.pkg.mk"
