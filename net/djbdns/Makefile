# $NetBSD: Makefile,v 1.4 2000/12/29 16:42:54 hubertf Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp

DISTNAME=	djbdns-1.02
PKGNAME=	djbdns-1.02nb2
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/ \
		ftp://ftp.innominate.org/gpa/djb/ \
		http://www.hungry.com/~fn/ \
		http://tinydns.org/
DISTFILES=	djbdns-1.02.tar.gz \
		djbdns-1.02-man.tar.gz \
		dnscache-log.pl.txt \
		tinydns-log.pl.txt

PATCH_SITES=    http://www.fefe.de/dns/
PATCHFILES=     djbdns-1.02-ipv6.diff.bz2
PATCH_DIST_STRIP=       -p1

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://cr.yp.to/djbdns.html

EXTRACT_ONLY=	djbdns-1.02.tar.gz \
		djbdns-1.02-man.tar.gz

ALL_TARGET=	it
INSTALL_TARGET=	setup check

post-extract:
	@${SED} 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' <  ${DISTDIR}/tinydns-log.pl.txt > ${WRKDIR}/tinydns-log.pl
	@${SED} 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' <  ${DISTDIR}/dnscache-log.pl.txt > ${WRKDIR}/dnscache-log.pl

post-patch:
	@${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO} "${CC} -s" > ${WRKSRC}/conf-ld
	@${ECHO} "${PREFIX}" > ${WRKSRC}/conf-home
	@${SED} 's|usage: dnscache-conf acct logacct /dnscache|usage: dnscache-conf acct logacct ${PREFIX}/etc/dnscache|' \
		< ${WRKSRC}/dnscache-conf.c > ${WRKSRC}/dnscache-conf.c.done; \
		${MV} ${WRKSRC}/dnscache-conf.c.done ${WRKSRC}/dnscache-conf.c
	@${SED} 's|usage: axfrdns-conf acct logacct /axfrdns /tinydns|usage: axfrdns-conf acct logacct ${PREFIX}/etc/axfrdns ${PREFIX}/etc/tinydns|' < ${WRKSRC}/axfrdns-conf.c > ${WRKSRC}/axfrdns-conf.c.done; \
		${MV} ${WRKSRC}/axfrdns-conf.c.done ${WRKSRC}/axfrdns-conf.c
	@${SED} 's|usage: pickdns-conf acct logacct /pickdns|usage: pickdns-conf acct logacct ${PREFIX}/etc/pickdns|' \
		< ${WRKSRC}/pickdns-conf.c > ${WRKSRC}/pickdns-conf.c.done; \
		${MV} ${WRKSRC}/pickdns-conf.c.done ${WRKSRC}/pickdns-conf.c
	@${SED} 's|usage: rbldns-conf acct logacct /rbldns|usage: rbldns-conf acct logacct ${PREFIX}/etc/rbldns|' \
		< ${WRKSRC}/rbldns-conf.c > ${WRKSRC}/rbldns-conf.c.done; \
		${MV} ${WRKSRC}/rbldns-conf.c.done ${WRKSRC}/rbldns-conf.c
	@${SED} 's|usage: tinydns-conf acct logacct /tinydns|usage: tinydns-conf acct logacct ${PREFIX}/etc/tinydns|' \
		< ${WRKSRC}/tinydns-conf.c > ${WRKSRC}/tinydns-conf.c.done; \
		${MV} ${WRKSRC}/tinydns-conf.c.done ${WRKSRC}/tinydns-conf.c
	@${SED} 's|usage: walldns-conf acct logacct /walldns|usage: walldns-conf acct logacct ${PREFIX}/etc/walldns|' \
		< ${WRKSRC}/walldns-conf.c > ${WRKSRC}/walldns-conf.c.done; \
		${MV} ${WRKSRC}/walldns-conf.c.done ${WRKSRC}/walldns-conf.c

post-install:
	@${INSTALL} ${WRKDIR}/tinydns-log.pl ${PREFIX}/bin/tinydns-log.pl
	@${INSTALL} ${WRKDIR}/dnscache-log.pl ${PREFIX}/bin/dnscache-log.pl
	@${INSTALL_DATA} ${WRKSRC}/dnsroots.global ${PREFIX}/etc/dnsroots.global
	@cd ${WRKDIR}/djbdns-1.02-man && ${INSTALL_MAN} dnsfilter.1 dnsip.1 dnsipq.1 dnsmx.1 dnsname.1 dnsq.1 dnsqr.1 dnstrace.1 dnstxt.1 ${PREFIX}/man/man1
	@cd ${WRKDIR}/djbdns-1.02-man && ${INSTALL_MAN} qualification.5 ${PREFIX}/man/man5
	@cd ${WRKDIR}/djbdns-1.02-man && ${INSTALL_MAN} axfr-get.8 axfrdns.8 dnscache-conf.8 dnscache.8 pickdns-conf.8 pickdns-data.8 pickdns.8 rbldns-conf.8 rbldns-data.8 rbldns.8 tinydns-conf.8 tinydns-data.8 tinydns.8 walldns-conf.8 walldns.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
