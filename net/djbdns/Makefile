# $NetBSD: Makefile,v 1.27 2003/09/24 03:28:12 schmonz Exp $
# FreeBSD Id: ports/net/djbdns/Makefile,v 1.4 2000/09/28 18:18:41 nbm Exp
#

DISTNAME=	djbdns-1.05
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/					\
		ftp://cr.yp.to/djbdns/					\
		http://smarden.org/pape/djb/manpages/			\
		http://www.hungry.com/~fn/				\
		http://tinydns.org/
DISTFILES=	${DISTNAME}.tar.gz					\
		${DISTNAME}-man-${MANVERSION}.tar.gz			\
		dnscache-log.pl.txt					\
		tinydns-log.pl.txt

PATCH_SITES=	http://www.fefe.de/dns/
PATCHFILES=	${DISTNAME}-ipv6.diff.bz2
PATCH_DIST_STRIP=       -p1

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cr.yp.to/djbdns.html
COMMENT=	Collection of secure and reliable DNS tools by Dan Bernstein

RESTRICTED=	"Redistribution of modified package is forbidden"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}				\
		${DISTNAME}-man-${MANVERSION}.tar.gz

REPLACE_PERL=	*.pl

ALL_TARGET=	it
INSTALL_TARGET=	setup check

MANVERSION=	20021211

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD=	3.0
.endif

post-extract:
	@${CP} ${DISTDIR}/tinydns-log.pl.txt ${WRKSRC}/tinydns-log.pl
	@${CP} ${DISTDIR}/dnscache-log.pl.txt ${WRKSRC}/dnscache-log.pl

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tinydns-log.pl ${PREFIX}/bin/tinydns-log
	${INSTALL_SCRIPT} ${WRKSRC}/dnscache-log.pl ${PREFIX}/bin/dnscache-log
	${INSTALL_DATA} ${WRKSRC}/dnsroots.global ${PREFIX}/etc/dnsroots.global
	cd ${WRKDIR}/djbdns-man; for i in 1 5 8; do			 \
	for j in *.$$i; do ${INSTALL_MAN} $$j ${PREFIX}/man/man$$i; done \
	done

.include "../../mk/bsd.pkg.mk"
