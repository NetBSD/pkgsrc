# $NetBSD: Makefile,v 1.2 1999/12/21 22:39:30 hubertf Exp $
#

DISTNAME=	sftp-0.4
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.xbill.org/pub/sftp/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.xbill.org/sftp/

GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftpserv	${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sftp.1 	${PREFIX}/man/man1/sftp.1
	${INSTALL_DATA}	${WRKSRC}/README	${PREFIX}/share/doc/README.sftp

.include "../../mk/bsd.pkg.mk"
