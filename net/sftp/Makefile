# $NetBSD: Makefile,v 1.10 2003/07/21 17:11:15 martti Exp $
#

DISTNAME=	sftp-0.5
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.xbill.org/pub/sftp/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.xbill.org/sftp/
COMMENT=	Ftp replacement that runs over an ssh tunnel

CONFLICTS=	openssh-[0-9]*

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftpserv	${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sftp.1 	${PREFIX}/man/man1/sftp.1
	${INSTALL_DATA}	${WRKSRC}/README	${PREFIX}/share/doc/README.sftp

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
