# $NetBSD: Makefile,v 1.1.1.1 2004/04/20 09:15:52 xtraeme Exp $
#

DISTNAME=	arpd-0.2
PKGNAME=	honeyd-arpd-0.2
WRKSRC=		${WRKDIR}/arpd
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	ARP daemon for honeyd

USE_PKGINSTALL= yes
RCD_SCRIPTS=	honeydarpd
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

CONFIGURE_ARGS+=    --with-libevent=${BUILDLINK_PREFIX.libevent}

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/sbin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${CP} ${WRKSRC}/arpd ${WRKSRC}/honeyd-arpd
	${CP} ${WRKSRC}/arpd.8 ${WRKSRC}/honeyd-arpd.8
	${INSTALL_PROGRAM} ${WRKSRC}/honeyd-arpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/honeyd-arpd.8 ${PREFIX}/man/man8

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

