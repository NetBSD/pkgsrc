# $NetBSD: Makefile,v 1.2 2000/09/03 12:36:55 wiz Exp $
#

DISTNAME=	ddclient-2.3.1
CATEGORIES=	net
MASTER_SITES=	http://burry.net/ddclient/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://burry.net/ddclient

NO_BUILD=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE

pre-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-install:
	${SED} \
		-e 's,@LOCALBASE@,${LOCALBASE},g' \
		-e 's,@PREFIX@,${PREFIX},g' \
		<${WRKSRC}/ddclient >${PREFIX}/bin/ddclient
	${CHMOD} +x ${PREFIX}/bin/ddclient
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/README				${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/COPYING				${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT				${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/sample-etc_cron.d_ddclient		${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/sample-etc_dhcpc_dhcpcd-eth0.exe	${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/sample-etc_ppp_ip-up.local 		${PREFIX}/share/doc/ddclient
	${INSTALL_DATA} ${WRKSRC}/sample-ddclient.conf 			${PREFIX}/etc/ddclient.conf-example
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ddclient/contrib
	${INSTALL_DATA}							${WRKSRC}/contrib/* ${PREFIX}/share/doc/ddclient/contrib

.include "../../mk/bsd.pkg.mk"
