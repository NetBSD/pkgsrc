# $NetBSD: Makefile,v 1.5 2003/09/19 23:08:30 dent Exp $

DISTNAME=	dcdflib.f-1.1
WRKSRC=		${WRKDIR}/dcdflib.f/src
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of Fortran Routines for Cumulative Distribution Functions

USE_FORTRAN=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dcdflib.f

.include "../../mk/bsd.pkg.mk"
