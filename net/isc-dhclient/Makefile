# $NetBSD: Makefile,v 1.2 2007/12/13 02:54:49 taca Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Client
COMPONENT=	client
SUBDIR=		client

CONF_FILES+=	${EGDIR}/dhclient.conf ${PKG_SYSCONFDIR}/dhclient.conf

RCD_SCRIPTS=	isc_dhclient
MAN_FILES=	man5/dhclient.conf.5 man5/dhclient.leases.5 \
		man8/dhclient-script.8 man8/dhclient.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/client/dhclient.conf ${EGDIR}

.include "../../net/isc-dhcp/Makefile.common"
.include "../../net/isc-dhcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
