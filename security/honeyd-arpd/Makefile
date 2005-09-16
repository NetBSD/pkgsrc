# $NetBSD: Makefile,v 1.8 2005/09/16 14:46:43 tv Exp $
#

DISTNAME=	arpd-0.2
PKGNAME=	honeyd-arpd-0.2
PKGREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	ARP daemon for honeyd

USE_PKGINSTALL= yes
RCD_SCRIPTS=	honeydarpd
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/arpd

CONFIGURE_ARGS+=    --with-libevent=${BUILDLINK_PREFIX.libevent}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/sbin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/arpd ${PREFIX}/sbin/honeyd-arpd
	${INSTALL_MAN} ${WRKSRC}/arpd.8 ${PREFIX}/man/man8/honeyd-arpd.8

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

