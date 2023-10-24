# $NetBSD: Makefile,v 1.15 2023/10/24 22:10:19 wiz Exp $

PKGNAME=	isc-dhcrelay-${DHVER}
PKGREVISION=	1
COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
BUILD_SUBDIR=	bind includes tests common omapip relay
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../net/isc-dhcp4/options.mk"

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
