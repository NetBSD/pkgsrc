# $NetBSD: Makefile,v 1.6 2013/04/18 04:23:17 agc Exp $

DISTNAME=	ipv6-toolkit-v1.3.4
PKGNAME=	${DISTNAME:C/-v/-/}
CATEGORIES=	security net
MASTER_SITES=	http://www.si6networks.com/tools/ipv6toolkit/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.si6networks.com/tools/ipv6toolkit
COMMENT=	IPv6 security assessment and troubleshooting tool
LICENSE=	gnu-gpl-v3

AUTO_MKDIRS=	yes

BINS=		address6 flow6 frag6 icmp6 jumbo6 na6 ni6 ns6 ra6 rd6 rs6 scan6 tcp6
MAN1=		address6.1 flow6.1 frag6.1 icmp6.1 jumbo6.1 na6.1 ni6.1 ns6.1
MAN1+=		ra6.1 rd6.1 rs6.1 scan6.1 tcp6.1
MAN5=		ipv6toolkit.conf.5

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

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
