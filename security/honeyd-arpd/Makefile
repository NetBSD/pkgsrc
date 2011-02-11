# $NetBSD: Makefile,v 1.24 2011/02/11 21:22:04 tnn Exp $
#

DISTNAME=	arpd-0.2
PKGNAME=	honeyd-arpd-0.2
PKGREVISION=	13
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/
COMMENT=	ARP daemon for honeyd

PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS=	honeydarpd
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/arpd

CONFIGURE_ARGS+=    --with-libevent=${BUILDLINK_PREFIX.libevent}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arpd ${DESTDIR}${PREFIX}/sbin/honeyd-arpd
	${INSTALL_MAN} ${WRKSRC}/arpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/honeyd-arpd.8

.include "../../devel/libevent/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
