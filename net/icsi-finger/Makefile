# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=	icsi-finger-1.0.27
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.icsi.berkeley.edu/pub/ai/stolcke/software/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@NetBSD.org
COMMENT=	Distributed finger service

WRKSRC=		${WRKDIR}/finger

XMPLD=		${PREFIX}/share/examples/icsi-finger
XMPLDT=		${XMPLD}/targets

INSTALLATION_DIRS=	bin libexec sbin

.include "../../mk/x11.buildlink3.mk"

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

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/finger ${PREFIX}/bin/gfinger
		${INSTALL_PROGRAM} ${WRKSRC}/src/fingerd ${PREFIX}/sbin/gfingerd
		${INSTALL_SCRIPT} ${WRKSRC}/src/vifinger ${PREFIX}/sbin
		${INSTALL_PROGRAM} ${WRKSRC}/src/packet2ascii ${PREFIX}/sbin
		${LN} -sf packet2ascii ${PREFIX}/sbin/ascii2packet
		${INSTALL_PROGRAM} ${WRKSRC}/src/in.fingerd ${PREFIX}/libexec
		${INSTALL_PROGRAM} ${WRKSRC}/src/in.cfingerd ${PREFIX}/libexec
		${INSTALL_PROGRAM} ${WRKSRC}/src/in.cfingerd ${PREFIX}/libexec
		${INSTALL_SCRIPT_DIR} ${PREFIX}/etc/fingerdir/targets
		${INSTALL_DATA_DIR} ${XMPLDT}
		${INSTALL_DATA} ${WRKSRC}/support/ttylocs ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/hostconfig ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/rc.local-add ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/services-add ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/inetd.conf-add ${XMPLD}
		(cd ${WRKSRC}/src; ${MAKE} install.man)
		(cd ${WRKSRC}/src; ${MAKE} TARGETD=${XMPLDT} install.targets)

.include "../../mk/bsd.pkg.mk"
