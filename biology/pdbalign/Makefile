# $NetBSD: Makefile,v 1.6 2012/09/11 20:32:13 asau Exp $
#

DISTNAME=		pdbalign
PKGNAME=		pdbalign-20030812
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/pdbalign/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		#empty
COMMENT=		Prediction of Protein Secondary Structure and Active Sites

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdbalign ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/distalign ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pdbdist ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
