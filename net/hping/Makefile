# $NetBSD: Makefile,v 1.3 2003/09/25 22:12:15 recht Exp $
#

DISTNAME=		hping2.0.0-rc2
PKGNAME=		hping-2.0.0.2
WRKSRC=			${WRKDIR}/hping2-rc2
CATEGORIES=		net
MASTER_SITES=		http://www.hping.org/

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.hping.org/
COMMENT=		Traceroute and ping using TCP and UDP as well as ICMP

HAS_CONFIGURE=		YES
MANPATH=		${PREFIX}/man
CONFIGURE_ENV+=		MANPATH="${MANPATH}"
NOT_FOR_PLATFORM=	NetBSD-0.* NetBSD-1.[0-4]*

BINMODE=		4755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping2 ${PREFIX}/sbin
	${LN} -s ../sbin/hping2 ${PREFIX}/sbin/hping
	${INSTALL_MAN} ${WRKSRC}/docs/hping2.8 ${PREFIX}/man/man8
	${LN} -s ../../man/man8/hping2.8 ${PREFIX}/man/man8/hping.8

.include "../../mk/bsd.pkg.mk"
