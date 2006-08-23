# $NetBSD: Makefile,v 1.11 2006/08/23 22:59:09 rpaulo Exp $

DISTNAME=	miredo-1.0.0
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
