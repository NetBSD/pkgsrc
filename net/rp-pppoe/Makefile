# $NetBSD: Makefile,v 1.34 2006/10/04 21:53:18 wiz Exp $

DISTNAME=	rp-pppoe-3.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/penguin/pppoe/ \
		http://roaringpenguin.luky.org/pppoe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roaringpenguin.com/penguin/open_source_rp-pppoe.php
COMMENT=	Roaring Penguin's PPP over Ethernet client

NOT_FOR_PLATFORM+=	Interix-*-* # no userland protocol stack support

CONFLICTS+=	mouse_pppoe<20000912nb1

USE_TOOLS+=	id
GNU_CONFIGURE=	YES
CONFIGURE_DIRS=	src
CONFIGURE_ENV+=	PPPD=${PPPD:Q}
CONFIGURE_ENV+=	ID=${TOOLS_ID:Q}
BUILD_DIRS=	src

RCD_SCRIPTS=	pppoe

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rp-pppoe
	cd ${WRKSRC}/configs && \
	${INSTALL_DATA} pppoe.conf pppoe-server-options \
	  ${PREFIX}/share/examples/rp-pppoe

.include "../../mk/bsd.pkg.mk"
