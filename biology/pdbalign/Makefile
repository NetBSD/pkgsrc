# $NetBSD: Makefile,v 1.2 2004/01/20 12:08:40 agc Exp $
#

DISTNAME=		pdbalign
PKGNAME=		pdbalign-20030812
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/pdbalign/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=               #empty
COMMENT=		Prediction of Protein Secondary Structure and Active Sites

WRKSRC=			${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdbalign ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/distalign ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pdbdist ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
