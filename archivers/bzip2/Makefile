# $NetBSD: Makefile,v 1.16 2001/06/10 01:14:58 wiz Exp $
#

DISTNAME=	bzip2-1.0.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://sourceware.cygnus.com/pub/bzip2/v100/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceware.cygnus.com/bzip2/
COMMENT=	Block-sorting file compressor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2 ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bunzip2
	${LN} -f ${PREFIX}/bin/bzip2 ${PREFIX}/bin/bzcat
	${INSTALL_PROGRAM} ${WRKSRC}/bzip2recover ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bzip2.1 ${PREFIX}/man/man1
	${RM} -f ${PREFIX}/man/man1/bunzip2.1 ${PREFIX}/man/man1/bzcat.1 ${PREFIX}/man/man1/bzip2recover.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bunzip2.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzcat.1
	${LN} -s ${PREFIX}/man/man1/bzip2.1 ${PREFIX}/man/man1/bzip2recover.1

.include "../../mk/bsd.pkg.mk"
