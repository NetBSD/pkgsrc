# $NetBSD: buildlink3.mk,v 1.18 2013/01/26 21:36:31 adam Exp $

BUILDLINK_TREE+=	netpbm

.if !defined(NETPBM_BUILDLINK3_MK)
NETPBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netpbm+=	netpbm>=10.11.6
BUILDLINK_ABI_DEPENDS.netpbm+=	netpbm>=10.35.80nb5
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # NETPBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-netpbm
