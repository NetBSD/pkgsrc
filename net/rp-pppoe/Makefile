# $NetBSD: Makefile,v 1.23 2003/06/02 01:17:45 jschauma Exp $

DISTNAME=	rp-pppoe-3.5
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE} \
		http://roaringpenguin.luky.org/pppoe/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.roaringpenguin.com/pppoe/
COMMENT=	Roaring Penguin's PPP over Ethernet client

CONFLICTS+=	mouse_pppoe<20000912nb1

USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PPPD=${PPPD}

RCD_SCRIPTS=	pppoe

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rp-pppoe
	cd ${WRKSRC}/../configs && \
	${INSTALL_DATA} pppoe.conf pppoe-server-options \
	  ${PREFIX}/share/examples/rp-pppoe

.include "../../mk/bsd.pkg.mk"
