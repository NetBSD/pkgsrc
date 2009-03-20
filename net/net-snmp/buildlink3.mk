# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:11 joerg Exp $

BUILDLINK_TREE+=	net-snmp

.if !defined(NET_SNMP_BUILDLINK3_MK)
NET_SNMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.net-snmp+=	net-snmp>=5.0.9nb3
BUILDLINK_ABI_DEPENDS.net-snmp+=	net-snmp>=5.2.1.2
BUILDLINK_PKGSRCDIR.net-snmp?=	../../net/net-snmp

.include "../../security/tcp_wrappers/buildlink3.mk"
.endif # NET_SNMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-net-snmp
