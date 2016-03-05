# $NetBSD: buildlink3.mk,v 1.14 2016/03/05 11:27:52 jperkin Exp $

BUILDLINK_TREE+=	net-snmp

.if !defined(NET_SNMP_BUILDLINK3_MK)
NET_SNMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.net-snmp+=	net-snmp>=5.0.9nb3
BUILDLINK_ABI_DEPENDS.net-snmp+=	net-snmp>=5.7.3nb3
BUILDLINK_PKGSRCDIR.net-snmp?=	../../net/net-snmp

pkgbase := net-snmp
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.net-snmp:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.include "../../security/tcp_wrappers/buildlink3.mk"
.endif # NET_SNMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-net-snmp
