# $NetBSD: Makefile,v 1.16 2003/09/17 19:40:55 grant Exp $
# FreeBSD Id: ports/sysutils/ucspi-tcp/Makefile,v 1.12 2000/07/10 01:41:24 steve Exp

DISTNAME=	ucspi-tcp-0.88
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/				\
		ftp://cr.yp.to/djbdns/					\
		ftp://ftp.innominate.org/pub/pape/djb/
DISTFILES=	${DISTNAME}.tar.gz					\
		${DISTNAME}-man-20010502.tar.gz

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cr.yp.to/ucspi-tcp.html
COMMENT=	Command-line tools for building TCP client-server applications

RESTRICTED=	"Redistribution of modified package is forbidden"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD=	3.0
.endif

post-configure:
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

post-install:
	cd ${WRKDIR}/${DISTNAME}-man &&					\
	${INSTALL_MAN} tcpserver.1 tcprules.1 tcprulescheck.1 argv0.1	\
		fixcrio.1 recordio.1 tcpclient.1 who@.1 date@.1		\
		finger@.1 http@.1 tcpcat.1 mconnect.1 addcr.1 delcr.1	\
		rblsmtpd.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
