# $NetBSD: Makefile,v 1.16 2001/11/13 23:12:15 zuntum Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp

DISTNAME=	djbdns-1.05
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/					\
		ftp://cr.yp.to/djbdns/					\
		ftp://ftp.innominate.org/pub/pape/djb/			\
		http://www.hungry.com/~fn/				\
		http://tinydns.org/
DISTFILES=	${DISTNAME}.tar.gz					\
		${DISTNAME}-man-20010212.tar.gz				\
		dnscache-log.pl.txt					\
		tinydns-log.pl.txt

PATCH_SITES=	http://www.fefe.de/dns/
PATCHFILES=	${DISTNAME}-ipv6.diff.bz2
PATCH_DIST_STRIP=       -p1

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://cr.yp.to/djbdns.html
COMMENT=	Collection of secure and reliable DNS tools by Dan Bernstein

RESTRICTED=	"Redistribution of modified package is forbidden"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}				\
		${DISTNAME}-man.tar.gz

ALL_TARGET=	it
INSTALL_TARGET=	setup check

.if (${MACHINE_ARCH} == "arm32" && ${CFLAGS} == "-O2")
CFLAGS=		-O0
.endif

post-extract:
	${SED} "s|/usr/bin/perl|${LOCALBASE}/bin/perl|"			\
		${DISTDIR}/tinydns-log.pl.txt > ${WRKDIR}/tinydns-log.pl
	${SED} "s|/usr/bin/perl|${LOCALBASE}/bin/perl|"			\
		${DISTDIR}/dnscache-log.pl.txt > ${WRKDIR}/dnscache-log.pl

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${STRIPFLAG} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tinydns-log.pl ${PREFIX}/bin/tinydns-log
	${INSTALL_SCRIPT} ${WRKDIR}/dnscache-log.pl ${PREFIX}/bin/dnscache-log
	${INSTALL_DATA} ${WRKSRC}/dnsroots.global ${PREFIX}/etc/dnsroots.global
	cd ${WRKDIR}/djbdns-man && ${INSTALL_MAN} dnsfilter.1 dnsip.1	\
	dnsipq.1 dnsmx.1 dnsname.1 dnsq.1 dnsqr.1 dnstrace.1 dnstxt.1	\
		${PREFIX}/man/man1
	cd ${WRKDIR}/djbdns-man && ${INSTALL_MAN} qualification.5	\
		${PREFIX}/man/man5
	cd ${WRKDIR}/djbdns-man && ${INSTALL_MAN} axfr-get.8 axfrdns.8	\
	dnscache-conf.8 dnscache.8 pickdns-conf.8 pickdns-data.8	\
	pickdns.8 rbldns-conf.8 rbldns-data.8 rbldns.8 tinydns-conf.8	\
	tinydns-data.8 tinydns.8 walldns-conf.8 walldns.8		\
		${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
