# $NetBSD: Makefile,v 1.2 2017/09/04 18:08:27 wiz Exp $
#

DISTNAME=		ndisc6-${VERSION}
PKGNAME=		tcptraceroute6-${VERSION}
VERSION=		1.0.3
CATEGORIES=		net
MASTER_SITES=		http://www.remlab.net/files/ndisc6/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		https://www.remlab.net/ndisc6/
COMMENT=		Traceroute6 implementation using TCP packets
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

#DOCDIR=			${PREFIX}/share/doc/tcptraceroute

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

INSTALL_PROGS+=		tcptraceroute6
INSTALL_PROGS+=		tracert6
INSTALL_PROGS+=		rltraceroute6

INSTALL_MANS+=		rltraceroute6.8

do-install:
	for p in ${INSTALL_PROGS}; do \
		${INSTALL_PROGRAM} ${WRKSRC}/src/$$p \
			${DESTDIR}${PREFIX}/sbin; \
	done
	for m in ${INSTALL_MANS}; do \
		${INSTALL_MAN} ${WRKSRC}/doc/$$m \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
	done
	(cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8; \
		for a in tcptraceroute6 ; do \
			${RM} -f $$a.8; \
			${LN} -s rltraceroute6.8 $$a.8; \
		done; \
	)

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
