# $NetBSD: Makefile,v 1.3 2009/01/04 00:58:41 adrianp Exp $
#

PKGNAME=	isc-dhcpd-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Server
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
