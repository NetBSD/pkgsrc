# $NetBSD: Makefile,v 1.19 2002/10/09 08:30:40 tron Exp $

DISTNAME=	rp-pppoe-3.5
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE} \
		http://roaringpenguin.luky.org/pppoe/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.roaringpenguin.com/pppoe/
COMMENT=	Roaring Penguin's PPP over Ethernet client

CONFLICTS+=	mouse_pppoe<20000912nb1

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PPPD=${PPPD}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-build:
	${SED} -e 's#$${PREFIX}#${PREFIX}#g' <${FILESDIR}/pppoe.sh \
	  >${WRKDIR}/pppoe.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/rp-pppoe
	cd ${WRKSRC}/../configs && \
	${INSTALL_DATA} pppoe.conf pppoe-server-options \
	  ${PREFIX}/share/examples/rp-pppoe
	${INSTALL_SCRIPT} ${WRKDIR}/pppoe.sh ${PREFIX}/etc/rc.d/pppoe

.include "../../mk/bsd.pkg.mk"
