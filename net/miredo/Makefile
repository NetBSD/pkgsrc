# $NetBSD: Makefile,v 1.8.2.1 2006/08/18 13:55:46 salo Exp $

DISTNAME=	miredo-0.9.9
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/miredo/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.simphalempin.com/dev/miredo/
COMMENT=	Teredo IPv6 tunneling

NOT_FOR_PLATFORM=	Interix-*-* NetBSD-[0-3]*-* SunOS-*-*

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/miredo
CONF_FILES=	${EGDIR}/miredo.conf-dist ${PKG_SYSCONFDIR}/miredo.conf
CONF_FILES+=	${EGDIR}/miredo-server.conf-dist \
		${PKG_SYSCONFDIR}/miredo-server.conf
CONF_FILES+=	${EGDIR}/isatapd.conf-dist ${PKG_SYSCONFDIR}/isatapd.conf

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
