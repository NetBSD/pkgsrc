# $NetBSD: buildlink3.mk,v 1.18 2022/06/28 11:35:04 wiz Exp $

BUILDLINK_TREE+=	net-snmp

.if !defined(NET_SNMP_BUILDLINK3_MK)
NET_SNMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.net-snmp+=	net-snmp>=5.0.9nb3
BUILDLINK_ABI_DEPENDS.net-snmp+=	net-snmp>=5.8nb4
BUILDLINK_PKGSRCDIR.net-snmp?=		../../net/net-snmp

pkgbase := net-snmp
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.net-snmp:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif # NET_SNMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-net-snmp
