# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:43 joerg Exp $

BUILDLINK_TREE+=	netpbm

.if !defined(NETPBM_BUILDLINK3_MK)
NETPBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netpbm+=	netpbm>=10.11.6
BUILDLINK_ABI_DEPENDS.netpbm+=	netpbm>=10.33nb1
BUILDLINK_PKGSRCDIR.netpbm?=	../../graphics/netpbm

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif # NETPBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-netpbm
