# $NetBSD: Makefile,v 1.12 2012/10/23 17:18:14 asau Exp $
#

DISTNAME=	choparp-20021107
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=choparp/}

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://choparp.sourceforge.net/
COMMENT=	Simple proxy arp daemon

NOT_FOR_PLATFORM=	Interix-*-* # does not have bpf(4) device

MANCOMPRESSED_IF_MANZ=	yes
MAKE_ENV+=	${BSD_MAKE_ENV}
INSTALLATION_DIRS=	${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.pkg.mk"
