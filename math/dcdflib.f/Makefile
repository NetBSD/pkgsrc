# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:39 jmmv Exp $

DISTNAME=	dcdflib.f-1.1
WRKSRC=		${WRKDIR}/dcdflib.f/src
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/page_2.html
COMMENT=	Library of Fortran Routines for Cumulative Distribution Functions

USE_FORTRAN=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dcdflib.f

.include "../../mk/bsd.pkg.mk"
