# $NetBSD: Makefile,v 1.1.1.1 2000/12/27 16:22:18 hubertf Exp $
# FreeBSD Id: ports/sysutils/ucspi-tcp/Makefile,v 1.12 2000/07/10 01:41:24 steve Exp

DISTNAME=	ucspi-tcp-0.88
CATEGORIES=	sysutils net
MASTER_SITES=	http://cr.yp.to/ucspi-tcp/

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
.for file in addcr argv0 delcr fixcrio mconnect-io rblsmtpd recordio tcpclient tcprules tcprulescheck tcpserver
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in date@ finger@ http@ mconnect who@ tcpcat
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
