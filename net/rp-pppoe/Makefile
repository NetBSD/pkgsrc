# $NetBSD: Makefile,v 1.12 2001/02/20 07:49:03 tron Exp $

DISTNAME=	rp-pppoe-2.6
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.roaringpenguin.com/pppoe/
COMMENT=	Roaring Penguin's PPP over Ethernet client

CONFLICTS+=	mouse_pppoe-*

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PPPD=${PPPD}

post-install:
	${MKDIR} ${PREFIX}/share/examples/rp-pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.conf ${WRKSRC}/pppoe-server-options \
	  ${PREFIX}/share/examples/rp-pppoe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OS_VERSION:M1.[0-4]*} != ""
DEPENDS+=	ppp>=2.3.10:../ppp

PPPD=		${LOCALBASE}/sbin/pppd
.else
PPPD=		/usr/sbin/pppd
.endif

.include "../../mk/bsd.pkg.mk"
