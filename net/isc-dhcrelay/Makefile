# $NetBSD: Makefile,v 1.2 2007/12/13 02:54:49 taca Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
COMPONENT=	relay
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
MAN_FILES=	man8/dhcrelay.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../net/isc-dhcp/Makefile.common"
.include "../../net/isc-dhcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
