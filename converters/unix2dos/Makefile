# $NetBSD: Makefile,v 1.1.1.1 2000/12/27 14:09:26 hubertf Exp $
# FreeBSD Id: ports/converters/unix2dos/Makefile,v 1.5 2000/07/04 10:31:42 sobomax Exp

DISTNAME=	unix2dos-1.2
CATEGORIES=	converters
MASTER_SITES=	http://www.fisicc-ufm.edu/~obonilla/files/ \
		ftp://ftp.guug.org/pub/

MAINTAINER=	zuntum@eik.pl

NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/unix2dos ${PREFIX}/bin/unix2dos
	${LN} -f ${PREFIX}/bin/unix2dos ${PREFIX}/bin/dos2unix
	${INSTALL_MAN} ${WRKDIR}/man1/unix2dos.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man1/dos2unix.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
