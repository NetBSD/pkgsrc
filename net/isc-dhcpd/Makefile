# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 20:04:29 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Server
COMPONENT=	server
SUBDIR=		omapip dhcpctl server

CONF_FILES+=	${EGDIR}/dhcpd.conf ${PKG_SYSCONFDIR}/dhcpd.conf

RCD_SCRIPTS=	isc_dhcpd
MAN_FILES=	man1/omshell.1 man3/dhcpctl.3 man3/omapi.3 man3/omshell.3 \
		man5/dhcpd.conf.5 man5/dhcpd.leases.5 man8/dhcpd.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/server/dhcpd.conf ${EGDIR}

.include "../../wip/isc-dhcp/Makefile.common"
.include "../../wip/isc-dhcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
