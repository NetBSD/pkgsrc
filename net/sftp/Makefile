# $NetBSD: Makefile,v 1.12 2004/10/03 00:17:58 tv Exp $
#

DISTNAME=	sftp-0.5
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.xbill.org/pub/sftp/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.xbill.org/sftp/
COMMENT=	Ftp replacement that runs over an ssh tunnel

CONFLICTS=	openssh-[0-9]*

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftp	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sftpserv	${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sftp.1 	${PREFIX}/man/man1/sftp.1
	${INSTALL_DATA}	${WRKSRC}/README	${PREFIX}/share/doc/README.sftp

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
