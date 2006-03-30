# $NetBSD: Makefile,v 1.8 2006/03/30 13:51:28 salo Exp $
#

DISTNAME=		hping2.0.0-rc3
PKGNAME=		hping-2.0.0.3
CATEGORIES=		net
MASTER_SITES=		http://www.hping.org/

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.hping.org/
COMMENT=		Command-line oriented TCP/IP packet assembler/analyzer

WRKSRC=			${WRKDIR}/hping2-rc3
HAS_CONFIGURE=		YES
MANPATH=		${PREFIX}/man
CONFIGURE_ENV+=		MANPATH=${MANPATH:Q}

INSTALLATION_DIRS=	man/man8 sbin

CONFIGURE_ENV+=		PCAPINCDIR=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ENV+=		PCAPLIBDIR=${BUILDLINK_PREFIX.libpcap}/lib

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${PREFIX}/sbin
	${LN} -s ../sbin/hping2 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${PREFIX}/man/man8
	${LN} -s ../../man/man8/hping2.8 ${PREFIX}/man/man8/hping.8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
