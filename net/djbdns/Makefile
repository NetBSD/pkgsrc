# $NetBSD: Makefile,v 1.5 2001/01/10 03:23:49 hubertf Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp

DISTNAME=	djbdns-1.03
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/ \
		ftp://ftp.innominate.org/gpa/djb/ \
		http://www.hungry.com/~fn/ \
		http://tinydns.org/
DISTFILES=	djbdns-1.03.tar.gz \
		djbdns-1.03-man.tar.gz \
		dnscache-log.pl.txt \
		tinydns-log.pl.txt

PATCH_SITES=    http://www.fefe.de/dns/
PATCHFILES=     djbdns-1.03-ipv6.diff.bz2
PATCH_DIST_STRIP=       -p1

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://cr.yp.to/djbdns.html

EXTRACT_ONLY=	djbdns-1.03.tar.gz \
		djbdns-1.03-man.tar.gz

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-extract:
	@${SED} 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' <  ${DISTDIR}/tinydns-log.pl.txt > ${WRKDIR}/tinydns-log.pl
	@${SED} 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' <  ${DISTDIR}/dnscache-log.pl.txt > ${WRKDIR}/dnscache-log.pl

post-patch:
	@${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO} "${PREFIX}" > ${WRKSRC}/conf-home

.for i in dnscache-conf axfrdns-conf pickdns-conf rbldns-conf tinydns-conf walldns-conf
	${SED} 's|usage: $i acct logacct /$i|usage: $i acct logacct ${PREFIX}/etc/$i|' \
		 < ${WRKSRC}/$i.c > ${WRKSRC}/$i.c.done
	${MV} ${WRKSRC}/$i.c.done ${WRKSRC}/$i.c
.endfor

post-install:
	@${INSTALL} ${WRKDIR}/tinydns-log.pl ${PREFIX}/bin/tinydns-log.pl
	@${INSTALL} ${WRKDIR}/dnscache-log.pl ${PREFIX}/bin/dnscache-log.pl
	@${INSTALL_DATA} ${WRKSRC}/dnsroots.global ${PREFIX}/etc/dnsroots.global
	@cd ${WRKDIR}/${DISTNAME}-man && ${INSTALL_MAN} dnsfilter.1 dnsip.1 dnsipq.1 dnsmx.1 dnsname.1 dnsq.1 dnsqr.1 dnstrace.1 dnstxt.1 ${PREFIX}/man/man1
	@cd ${WRKDIR}/${DISTNAME}-man && ${INSTALL_MAN} qualification.5 ${PREFIX}/man/man5
	@cd ${WRKDIR}/${DISTNAME}-man && ${INSTALL_MAN} axfr-get.8 axfrdns.8 dnscache-conf.8 dnscache.8 pickdns-conf.8 pickdns-data.8 pickdns.8 rbldns-conf.8 rbldns-data.8 rbldns.8 tinydns-conf.8 tinydns-data.8 tinydns.8 walldns-conf.8 walldns.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
