# $NetBSD: Makefile,v 1.5 2013/03/12 20:32:00 agc Exp $

DISTNAME=	ipv6-toolkit-v1.3.3
PKGNAME=	ipv6-toolkit-1.3.3
CATEGORIES=	security net
MASTER_SITES=	http://www.si6networks.com/tools/ipv6toolkit/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.si6networks.com/tools/ipv6toolkit
COMMENT=	IPv6 security assessment and troubleshooting tool
LICENSE=	gnu-gpl-v3

AUTO_MKDIRS=	yes

BINS=		flow6 frag6 icmp6 jumbo6 na6 ni6 ns6 ra6 rd6 rs6 scan6 tcp6
MAN1=		flow6.1 frag6.1 icmp6.1 scan6.1
MAN5=		ipv6toolkit.conf.5
PDFS=		flow6-manual.pdf frag6-manual.pdf icmp6-manual.pdf jumbo6-manual.pdf
PDFS+=		na6-manual.pdf ni6-manual.pdf ns6-manual.pdf ra6-manual.pdf
PDFS+=		rd6-manual.pdf rs6-manual.pdf scan6-manual.pdf tcp6-manual.pdf

do-install:
	for f in ${BINS}; do						\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin/$$f; \
	done
	for f in ${MAN1}; do						\
		${INSTALL_MAN} ${WRKSRC}/manuals/$$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$f; \
	done
	for f in ${MAN5}; do						\
		${INSTALL_MAN} ${WRKSRC}/manuals/$$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/$$f; \
	done
	for f in ${PDFS}; do						\
		${INSTALL_DATA} ${WRKSRC}/manuals/$$f ${DESTDIR}${PREFIX}/share/doc/ipv6-toolkit/$$f; \
	done

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
