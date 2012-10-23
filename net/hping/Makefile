# $NetBSD: Makefile,v 1.12 2012/10/23 17:18:27 asau Exp $
#

DISTNAME=		hping2.0.0-rc3
PKGNAME=		hping-2.0.0.3
CATEGORIES=		net
MASTER_SITES=		http://www.hping.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hping.org/
COMMENT=		Command-line oriented TCP/IP packet assembler/analyzer

WRKSRC=			${WRKDIR}/hping2-rc3
HAS_CONFIGURE=		YES
MANPATH=		${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		MANPATH=${MANPATH:Q}

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

CONFIGURE_ENV+=		PCAPINCDIR=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ENV+=		PCAPLIBDIR=${BUILDLINK_PREFIX.libpcap}/lib

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${DESTDIR}${PREFIX}/sbin
	${LN} -s hping2 ${DESTDIR}${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${LN} -s hping2.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/hping.8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
