# $NetBSD: Makefile,v 1.15 2001/03/18 18:55:28 tron Exp $

DISTNAME=	rp-pppoe-2.8
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.roaringpenguin.com/pppoe/
COMMENT=	Roaring Penguin's PPP over Ethernet client

CONFLICTS+=	mouse_pppoe<20000912nb1

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PPPD=${PPPD}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OS_VERSION:M1.[0-4]*} != ""
DEPENDS+=	ppp>=2.3.10:../ppp

PPPD=		${LOCALBASE}/sbin/pppd
.else
PPPD=		/usr/sbin/pppd
.endif

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
