# $NetBSD: Makefile,v 1.11 2019/08/27 08:12:01 adam Exp $

PKGNAME=	isc-dhcrelay-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
BUILD_SUBDIR=	bind includes tests common omapip relay
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../net/isc-dhcp4/options.mk"

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
