# $NetBSD: Makefile,v 1.4 2001/01/29 15:25:55 wiz Exp $
#

DISTNAME=	ddclient-2.3.2
CATEGORIES=	net
MASTER_SITES=	http://burry.net/ddclient/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://burry.net/ddclient

NO_BUILD=	yes

do-install:
	${SED} \
		-e 's,@LOCALBASE@,${LOCALBASE},g' \
		-e 's,@PREFIX@,${PREFIX},g' \
		${WRKSRC}/ddclient >${PREFIX}/bin/ddclient
	${CHMOD} +x ${PREFIX}/bin/ddclient
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ddclient
	for F in README COPYING COPYRIGHT sample-etc_cron.d_ddclient	     \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local; \
	do								     \
		${INSTALL_DATA} ${WRKSRC}/$$F ${PREFIX}/share/doc/ddclient; \
	done
	${INSTALL_DATA} ${WRKSRC}/sample-ddclient.conf			     \
		${PREFIX}/etc/ddclient.conf-example
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ddclient/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/*				     \
		 ${PREFIX}/share/doc/ddclient/contrib

.include "../../mk/bsd.pkg.mk"
