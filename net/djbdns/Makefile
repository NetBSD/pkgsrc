# $NetBSD: Makefile,v 1.2 2000/12/27 23:29:57 hubertf Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp

DISTNAME=	djbdns-1.02
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/ \
		ftp://ftp.innominate.org/gpa/djb/
DISTFILES=	djbdns-1.02.tar.gz \
		djbdns-1.02-man.tar.gz

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
	@cd ${WRKDIR}/djbdns-1.02-man && ${INSTALL_MAN} dnsfilter.1 dnsip.1 dnsipq.1 dnsmx.1 dnsname.1 dnsq.1 dnsqr.1 dnstrace.1 dnstxt.1 ${PREFIX}/man/man1
	@cd ${WRKDIR}/djbdns-1.02-man && ${INSTALL_MAN} qualification.5 ${PREFIX}/man/man5
	@cd ${WRKDIR}/djbdns-1.02-man && ${INSTALL_MAN} axfr-get.8 axfrdns.8 dnscache-conf.8 dnscache.8 pickdns-conf.8 pickdns-data.8 pickdns.8 rbldns-conf.8 rbldns-data.8 rbldns.8 tinydns-conf.8 tinydns-data.8 tinydns.8 walldns-conf.8 walldns.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
