# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:25:01 wiz Exp $

BUILDLINK_TREE+=	isc-dhcp

.if !defined(ISC_DHCP_BUILDLINK3_MK)
ISC_DHCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.isc-dhcp+=	isc-dhcp>=4.3.0
BUILDLINK_ABI_DEPENDS.isc-dhcp?=		isc-dhcp>=4.4.3p1nb1
BUILDLINK_PKGSRCDIR.isc-dhcp?=		../../net/isc-dhcp4
.endif # ISC_DHCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-isc-dhcp
