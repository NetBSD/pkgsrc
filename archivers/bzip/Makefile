# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:07 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1996/12/07 09:28:40 max Exp 
#

DISTNAME=       bzip-0.21
CATEGORIES=	archivers
MASTER_SITES=   http://www.cs.man.ac.uk/arch/people/j-seward/

MAINTAINER=     andreas@klemm.gtn.com

NO_CDROM=       "Restrictive copyright (don't sell for profit)"
MAN1=		bzip.1 bunzip.1

pre-install:
	@${CAT} ${FILESDIR}/COPYRIGHT

do-install:
	${RM} -f ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${PREFIX}/bin/bzip
	ln -fs ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${PREFIX}/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${PREFIX}/man/man1/bunzip.1

.include "../../mk/bsd.pkg.mk"
