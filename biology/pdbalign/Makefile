# $NetBSD: Makefile,v 1.1.1.1 2003/09/26 03:15:28 jschauma Exp $
#

DISTNAME=		pdbalign
PKGNAME=		pdbalign-20030812
WRKSRC=			${WRKDIR}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/pdbalign/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=               #empty
COMMENT=		Prediction of Protein Secondary Structure and Active Sites

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdbalign ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/distalign ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pdbdist ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
