# $NetBSD: Makefile,v 1.11 2024/08/22 17:05:59 gdt Exp $
#

DISTNAME=		stride
PKGNAME=		stride-20030804
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/stride/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://wolf.bi.umist.ac.uk/unix/stride.html
COMMENT=		Protein secondary structure assignment from atomic coordinates

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/stride ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
