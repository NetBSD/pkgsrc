# $NetBSD: Makefile,v 1.4 2004/08/15 13:37:24 ben Exp $
#

DISTNAME=		stride
PKGNAME=		stride-20030804
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://wolf.bi.umist.ac.uk/unix/stride.html
COMMENT=		Protein secondary structure assignment from atomic coordinates

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/stride ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
