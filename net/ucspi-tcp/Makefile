# $NetBSD: Makefile,v 1.2 2001/01/10 03:16:16 hubertf Exp $
# FreeBSD Id: ports/sysutils/ucspi-tcp/Makefile,v 1.12 2000/07/10 01:41:24 steve Exp

DISTNAME=	ucspi-tcp-0.88
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/ \
		ftp://ftp.innominate.org/gpa/djb/
DISTFILES=	ucspi-tcp-0.88.tar.gz \
		ucspi-tcp-0.88-man.tar.gz

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://cr.yp.to/ucspi-tcp.html

ALL_TARGET=	prog install instcheck

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

post-configure:
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} -s > ${WRKSRC}/conf-ld

do-install:
.for f in addcr argv0 delcr fixcrio mconnect-io rblsmtpd recordio tcpclient tcprules tcprulescheck tcpserver
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in date@ finger@ http@ mconnect who@ tcpcat
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

post-install:
	@cd ${WRKDIR}/${DISTNAME}-man && ${INSTALL_MAN} tcpserver.1 tcprules.1 tcprulescheck.1 argv0.1 fixcrio.1 recordio.1 tcpclient.1 who@.1 date@.1 finger@.1 http@.1 tcpcat.1 mconnect.1 addcr.1 delcr.1 rblsmtpd.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
