# $NetBSD: Makefile,v 1.4 2008/01/03 12:25:02 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
COMPONENT=	relay
PKGREVISION=	2
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
MAN_FILES=	man8/dhcrelay.8
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "../../net/isc-dhcp/Makefile.common"
.include "../../net/isc-dhcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
