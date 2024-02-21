# $NetBSD: buildlink3.mk,v 1.20 2024/02/21 10:21:00 wiz Exp $

BUILDLINK_TREE+=	net-snmp

.if !defined(NET_SNMP_BUILDLINK3_MK)
NET_SNMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.net-snmp+=	net-snmp>=5.0.9nb3
BUILDLINK_ABI_DEPENDS.net-snmp+=	net-snmp>=5.9.3nb2
BUILDLINK_PKGSRCDIR.net-snmp?=		../../net/net-snmp

pkgbase := net-snmp
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.net-snmp:Mssl}
.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.endif # NET_SNMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-net-snmp
