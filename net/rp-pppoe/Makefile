# $NetBSD: Makefile,v 1.3 2000/07/17 21:11:45 tron Exp $

DISTNAME=	rp-pppoe-2.0
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/pppoe/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~minaret/pppoe/

DEPENDS+=	ppp>=2.3.10:../ppp

CONFLICTS+=	mouse_pppoe-*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PPPD=${LOCALBASE}/sbin/pppd

post-install:
	${INSTALL_DATA} ${WRKSRC}/pppoe.conf ${PREFIX}/share/doc/rp-pppoe

.include "../../mk/bsd.pkg.mk"
