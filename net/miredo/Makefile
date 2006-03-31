# $NetBSD: Makefile,v 1.4 2006/03/31 23:21:33 rpaulo Exp $

DISTNAME=	miredo-0.8.0
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/miredo/v0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.simphalempin.com/dev/miredo/
COMMENT=	Teredo IPv6 tunneling

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-[0-3]*-* SunOS-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/miredo
CONF_FILES=	${EGDIR}/miredo.conf-dist ${PKG_SYSCONFDIR}/miredo.conf

INSTALLATION_DIRS=	share/examples/miredo

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/miredo.conf-dist ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/miredo-server.conf-dist ${EGDIR}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
