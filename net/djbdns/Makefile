# $NetBSD: Makefile,v 1.1.1.1 2000/12/27 16:04:23 hubertf Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp

DISTNAME=	djbdns-1.02
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://cr.yp.to/djbdns.html

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-patch:
	@${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO} "${PREFIX}" > ${WRKSRC}/conf-home

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dnsroots.global ${PREFIX}/etc/dnsroots.global

.include "../../mk/bsd.pkg.mk"
