# $NetBSD: Makefile,v 1.5 2001/04/12 10:44:38 wennmach Exp $
#

DISTNAME=	sftp-0.5
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.xbill.org/pub/sftp/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.xbill.org/sftp/
COMMENT=	Ftp replacement that runs over an ssh tunnel

CONFLICTS=	openssh-*

GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftpserv	${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sftp.1 	${PREFIX}/man/man1/sftp.1
	${INSTALL_DATA}	${WRKSRC}/README	${PREFIX}/share/doc/README.sftp

.include "../../mk/bsd.pkg.mk"
