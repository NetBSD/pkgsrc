# $NetBSD: Makefile,v 1.1.1.1 2001/07/30 19:43:49 nra Exp $
# FreeBSD Id: ports/ftp/yale-tftpd/Makefile,v 1.14 2000/04/12 05:31:29 mharo Exp

DISTNAME=	yale-tftpd-3.0
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	packages@netbsd.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

NO_WRKSUBDIR=

post-configure:
	${MV} ${WRKSRC}/tftpd.8 ${WRKSRC}/tftpd.8.in
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${WRKSRC}/tftpd.8.in > ${WRKSRC}/tftpd.8

.include "../../mk/bsd.pkg.mk"
