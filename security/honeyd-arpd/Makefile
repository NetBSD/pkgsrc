# $NetBSD: Makefile,v 1.17 2008/04/22 18:06:09 tnn Exp $
#

DISTNAME=	arpd-0.2
PKGNAME=	honeyd-arpd-0.2
PKGREVISION=	8
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/
COMMENT=	ARP daemon for honeyd

RCD_SCRIPTS=	honeydarpd
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/arpd

CONFIGURE_ARGS+=    --with-libevent=${BUILDLINK_PREFIX.libevent}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arpd ${PREFIX}/sbin/honeyd-arpd
	${INSTALL_MAN} ${WRKSRC}/arpd.8 ${PREFIX}/${PKGMANDIR}/man8/honeyd-arpd.8

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
