# $NetBSD: Makefile,v 1.7 2004/10/03 00:12:55 tv Exp $

DISTNAME=	dcdflib.f-1.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mdacc.tmc.edu/pub/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://odin.mdacc.tmc.edu/anonftp/
COMMENT=	Library of Fortran Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.f/src
USE_FORTRAN=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${PREFIX}/share/doc/dcdflib.f
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dcdflib.f

.include "../../mk/bsd.pkg.mk"
