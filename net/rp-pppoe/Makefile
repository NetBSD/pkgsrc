# $NetBSD: Makefile,v 1.35 2006/11/01 15:17:13 martin Exp $

DISTNAME=	rp-pppoe-3.8
# PKGREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/files/download/

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
MAKE_ENV+=	OPSYS=${OPSYS}
BUILD_DIRS=	src

RCD_SCRIPTS=	pppoe

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rp-pppoe
	cd ${WRKSRC}/configs && \
	${INSTALL_DATA} pppoe.conf pppoe-server-options \
	  ${PREFIX}/share/examples/rp-pppoe

.include "../../mk/bsd.pkg.mk"
