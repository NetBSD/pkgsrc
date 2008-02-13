# $NetBSD: Makefile,v 1.1.1.1 2008/02/13 22:06:15 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Server
COMPONENT=	server
SUBDIR=		omapip dhcpctl server

CONF_FILES+=	${EGDIR}/dhcpd.conf ${PKG_SYSCONFDIR}/dhcpd.conf
RCD_SCRIPTS=	isc_dhcpd
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/server/dhcpd.conf ${EGDIR}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
