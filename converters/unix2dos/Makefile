# $NetBSD: Makefile,v 1.18 2005/06/16 06:57:43 jlam Exp $

DISTNAME=	unix2dos-1.2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		http://www.fisicc-ufm.edu/~obonilla/files/		\
		ftp://ftp.guug.org/pub/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Translate ASCII files to/from DOS (cr/lf) and UNIX (lf)

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix2dos ${PREFIX}/bin/unix2dos
	${LN} -f ${PREFIX}/bin/unix2dos ${PREFIX}/bin/dos2unix
	${INSTALL_MAN} ${WRKSRC}/man1/unix2dos.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man1/dos2unix.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
