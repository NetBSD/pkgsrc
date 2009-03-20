# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:09 joerg Exp $

BUILDLINK_TREE+=	isc-dhcp

.if !defined(ISC_DHCP_BUILDLINK3_MK)
ISC_DHCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.isc-dhcp+=	isc-dhcp>=4.1.0
BUILDLINK_PKGSRCDIR.isc-dhcp?=	../../net/isc-dhcp4
.endif # ISC_DHCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-isc-dhcp
