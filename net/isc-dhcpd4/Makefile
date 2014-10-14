# $NetBSD: Makefile,v 1.13 2014/10/14 13:53:01 taca Exp $

PKGNAME=	isc-dhcpd-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Server
BUILD_SUBDIR=	bind includes tests common omapip dhcpctl server
SUBDIR=		omapip dhcpctl server

CONF_FILES+=	${EGDIR}/dhcpd.conf ${PKG_SYSCONFDIR}/dhcpd.conf
#CONF_FILES+=	${EGDIR}/dhcpd6.conf ${PKG_SYSCONFDIR}/dhcpd6.conf

RCD_SCRIPTS=	isc_dhcpd isc_dhcpd6
SMF_METHODS=	isc-dhcpd

FILES_SUBST+=	DHCP_HOME=${DHCP_HOME:Q}
FILES_SUBST+=	DHCP_PID=${DHCP_PID:Q}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/server/dhcpd.conf.example \
		${DESTDIR}${EGDIR}/dhcpd.conf

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
