# $NetBSD: Makefile,v 1.41 2012/10/23 17:19:06 asau Exp $

DISTNAME=	rp-pppoe-3.8
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.roaringpenguin.com/files/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roaringpenguin.com/products/pppoe
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

INSTALLATION_DIRS+=	share/examples/rp-pppoe

INSTALL_MAKE_FLAGS+=	RPM_INSTALL_ROOT=${DESTDIR}

post-install:
	cd ${WRKSRC}/configs && \
	${INSTALL_DATA} pppoe.conf pppoe-server-options \
	    ${DESTDIR}${PREFIX}/share/examples/rp-pppoe

.include "../../mk/bsd.pkg.mk"
