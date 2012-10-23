# $NetBSD: Makefile,v 1.6 2012/10/23 17:18:29 asau Exp $
#

PKGNAME=	isc-dhcrelay-${DHVER}
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
BUILD_SUBDIR=	bind includes tests common omapip relay
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
