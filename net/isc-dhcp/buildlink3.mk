# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:08 joerg Exp $

BUILDLINK_TREE+=	isc-dhcp-base

.if !defined(ISC_DHCP_BASE_BUILDLINK3_MK)
ISC_DHCP_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.isc-dhcp-base+=	isc-dhcp-base>=3.1.0<4
BUILDLINK_PKGSRCDIR.isc-dhcp-base?=	../../net/isc-dhcp
.endif # ISC_DHCP_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-isc-dhcp-base
