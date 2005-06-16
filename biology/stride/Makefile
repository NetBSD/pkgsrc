# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:41 jlam Exp $
#

DISTNAME=		stride
PKGNAME=		stride-20030804
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://wolf.bi.umist.ac.uk/unix/stride.html
COMMENT=		Protein secondary structure assignment from atomic coordinates

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/stride ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
