# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:46 rillig Exp $
#

DISTNAME=		hping2.0.0-rc2
PKGNAME=		hping-2.0.0.2
CATEGORIES=		net
MASTER_SITES=		http://www.hping.org/

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.hping.org/
COMMENT=		Traceroute and ping using TCP and UDP as well as ICMP

WRKSRC=			${WRKDIR}/hping2-rc2
HAS_CONFIGURE=		YES
MANPATH=		${PREFIX}/man
CONFIGURE_ENV+=		MANPATH=${MANPATH:Q}
NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[0-4]*-*

BINMODE=		4755
INSTALLATION_DIRS=	man/man8 sbin

CONFIGURE_ENV+=		PCAPINCDIR=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ENV+=		PCAPLIBDIR=${BUILDLINK_PREFIX.libpcap}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${PREFIX}/sbin
	${LN} -s ../sbin/hping2 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${PREFIX}/man/man8
	${LN} -s ../../man/man8/hping2.8 ${PREFIX}/man/man8/hping.8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
