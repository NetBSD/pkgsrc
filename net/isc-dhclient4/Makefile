# $NetBSD: Makefile,v 1.2 2008/12/21 21:24:08 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Client
COMPONENT=	client
PKGREVISION=	1
SUBDIR=		client

CONF_FILES+=	${EGDIR}/dhclient.conf ${PKG_SYSCONFDIR}/dhclient.conf

RCD_SCRIPTS=	isc_dhclient
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/client/dhclient.conf ${EGDIR}

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
