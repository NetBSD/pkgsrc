# $NetBSD: Makefile,v 1.2 1999/07/05 20:45:43 tron Exp $
#

DISTNAME=	icsi-finger-1.0.27
WRKSRC=		${WRKDIR}/finger
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.icsi.berkeley.edu/pub/ai/stolcke/software/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@netbsd.org

USE_X11=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE

XMPLD=		${PREFIX}/share/examples/icsi-finger
XMPLDT=		${XMPLD}/targets

pre-configure:
		${RM} -f ${WRKSRC}/config.h
		${SED}	-e s@/usr/local@${PREFIX}@	\
			-e s@/usr/pkg@${PREFIX}@	\
			files/config.h.netbsd > ${WRKSRC}/config.h
		${MV} -f ${WRKSRC}/support/inetd.conf-add \
			${WRKSRC}/support/inetd.conf-add.bak
		${SED}	-e s@/usr/local/etc@${PREFIX}/libexec@      \
			-e s@/usr/local/etc@${PREFIX}/libexec@      \
			${WRKSRC}/support/inetd.conf-add.bak > \
			${WRKSRC}/support/inetd.conf-add
		${MV} -f ${WRKSRC}/support/rc.local-add \
			${WRKSRC}/support/rc.local-add.bak
		${SED}  -e s@/usr/local/bin/@${PREFIX}/sbin/g@      \
			${WRKSRC}/support/rc.local-add.bak > \
			${WRKSRC}/support/rc.local-add
		for i in ${WRKSRC}/src/targets/x-.busy \
			${WRKSRC}/src/targets/x-.down; do \
			${MV} $$i $$i.bak; ${SED} -e s@nawk@awk@ \
				-e s@/usr/local/etc@${PREFIX}/libexec@ \
				$$i.bak > $$i ; \
			${RM} -f $$i.bak ; \
		done
		${SED} -e s@/usr/pkg@${PREFIX}@g ${PKGDIR}/MESSAGE | \
			fmt >${WRKDIR}/MESSAGE

do-${INSTALL}:
		${INSTALL} -c -m 755 ${WRKSRC}/src/finger ${PREFIX}/bin/gfinger
		${INSTALL} -c -m 755 ${WRKSRC}/src/fingerd ${PREFIX}/sbin/gfingerd
		${INSTALL} -c -m 755 ${WRKSRC}/src/vifinger ${PREFIX}/sbin
		${INSTALL} -c -m 755 ${WRKSRC}/src/packet2ascii ${PREFIX}/sbin
		${LN} -sf ${PREFIX}/sbin/packet2ascii \
			${PREFIX}/sbin/ascii2packet
		${INSTALL} -c -m 755 ${WRKSRC}/src/in.fingerd ${PREFIX}/libexec
		${INSTALL} -c -m 755 ${WRKSRC}/src/in.cfingerd ${PREFIX}/libexec
		${INSTALL} -c -m 755 ${WRKSRC}/src/in.cfingerd ${PREFIX}/libexec
		-${MKDIR} ${PREFIX}/etc/fingerdir/targets
		-${MKDIR} ${XMPLDT}
		${INSTALL} -c -m 644 ${WRKSRC}/support/ttylocs ${XMPLD}
		${INSTALL} -c -m 644 ${WRKSRC}/support/hostconfig ${XMPLD}
		${INSTALL} -c -m 644 ${WRKSRC}/support/rc.local-add ${XMPLD}
		${INSTALL} -c -m 644 ${WRKSRC}/support/services-add ${XMPLD}
		${INSTALL} -c -m 644 ${WRKSRC}/support/inetd.conf-add ${XMPLD}
		(cd ${WRKSRC}/src; ${MAKE} ${INSTALL}.man)
		(cd ${WRKSRC}/src; ${MAKE} TARGETD=${XMPLDT} ${INSTALL}.targets )

.include "../../mk/bsd.pkg.mk"
