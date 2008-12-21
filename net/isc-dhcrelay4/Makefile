# $NetBSD: Makefile,v 1.2 2008/12/21 21:24:08 adrianp Exp $
#

COMMENT=	ISC Dynamic Host Configuration Protocol (DHCP) Relay
COMPONENT=	relay
PKGREVISION=	1
SUBDIR=		relay

RCD_SCRIPTS=	isc_dhcrelay
FILES_SUBST+=	DHCP_HOME=${DHCP_HOME}

.include "${.CURDIR}/../isc-dhcp4/options.mk"

.include "../../net/isc-dhcp4/Makefile.common"
.include "../../net/isc-dhcp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
