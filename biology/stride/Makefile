# $NetBSD: Makefile,v 1.3 2004/04/11 04:10:37 snj Exp $
#

DISTNAME=		stride
PKGNAME=		stride-20030804
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www-db.embl-heidelberg.de/jss/servlet/de.embl.bk.wwwTools.GroupLeftEMBL/argos/stride/stride_info.html
COMMENT=		Protein secondary structure assignment from atomic coordinates

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/stride ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
