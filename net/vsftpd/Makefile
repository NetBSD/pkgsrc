# $NetBSD: Makefile,v 1.1.1.1 2001/06/19 11:32:02 zuntum Exp $
#

DISTNAME=	vsftpd-0.9.1
CATEGORIES=	net
MASTER_SITES=	ftp://ferret.lmh.ox.ac.uk/pub/linux/

MAINTAINER=	vaneth@krasnik.org
HOMEPAGE=	http://ferret.lmh.ox.ac.uk/
COMMENT=	FTP server that aims to be very secure

ALL_TARGET=	#

post-install:
	${INSTALL_MAN} ${WRKSRC}/vsftpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/vsftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/vsftpd
	${INSTALL_DATA} ${WRKSRC}/vsftpd.conf ${PREFIX}/share/examples/vsftpd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vsftpd
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/vsftpd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/vsftpd

.include "../../mk/bsd.pkg.mk"
