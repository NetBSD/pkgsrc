# $NetBSD: Makefile,v 1.6 2000/08/12 16:54:44 tron Exp $

DISTNAME=	rp-pppoe-2.2
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/pppoe/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~minaret/pppoe/

CONFLICTS+=	mouse_pppoe-*

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PPPD=${PPPD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pppoe.conf ${PREFIX}/share/doc/rp-pppoe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OS_VERSION:M1.[0-4]*} != ""
DEPENDS+=	ppp>=2.3.10:../ppp

PPPD=		${LOCALBASE}/sbin/pppd
.else
PPPD=		/usr/sbin/pppd
.endif

.include "../../mk/bsd.pkg.mk"
