# $NetBSD: options.mk,v 1.4 2011/08/06 11:52:16 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mrtg
PKG_SUPPORTED_OPTIONS=	inet6 mrtg-snmpv3

.include "../../mk/bsd.options.mk"

###
### Use an external SNMP module to get SNMPv3 support
###
.if !empty(PKG_OPTIONS:Mmrtg-snmpv3)
DEPENDS+=	p5-Net-SNMP-[0-9]*:../../net/p5-Net-SNMP
.endif

###
### Support for IPv6 enabled devices
###
.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=	p5-IO-Socket-INET6>=2.67:../../net/p5-IO-Socket-INET6
.endif
