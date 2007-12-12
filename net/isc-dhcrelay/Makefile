# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 20:05:11 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
COMPONENT=	relay
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
MAN_FILES=	man8/dhcrelay.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../wip/isc-dhcp/Makefile.common"
.include "../../wip/isc-dhcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
