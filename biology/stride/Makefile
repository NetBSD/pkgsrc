# $NetBSD: Makefile,v 1.2 2004/01/20 12:08:40 agc Exp $
#

DISTNAME=		stride
PKGNAME=		stride-20030804
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www-db.embl-heidelberg.de/jss/servlet/de.embl.bk.wwwTools.GroupLeftEMBL/argos/stride/stride_info.html
COMMENT=		Protein secondary structure assignment from atomic coordinates

WRKSRC=			${WRKDIR}
USE_BUILDLINK2=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/stride ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
