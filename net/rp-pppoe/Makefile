# $NetBSD: Makefile,v 1.27 2005/06/23 16:48:27 kristerw Exp $

DISTNAME=	rp-pppoe-3.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE} \
		http://roaringpenguin.luky.org/pppoe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.roaringpenguin.com/pppoe/
COMMENT=	Roaring Penguin's PPP over Ethernet client

CONFLICTS+=	mouse_pppoe<20000912nb1

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_PKGINSTALL=	YES
USE_TOOLS+=	id
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PPPD=${PPPD}
CONFIGURE_ENV+=	ac_cv_path_ID="${TOOLS_ID}"

RCD_SCRIPTS=	pppoe

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rp-pppoe
	cd ${WRKSRC}/../configs && \
	${INSTALL_DATA} pppoe.conf pppoe-server-options \
	  ${PREFIX}/share/examples/rp-pppoe

.include "../../mk/bsd.pkg.mk"
