# $NetBSD: buildlink3.mk,v 1.11 2019/08/30 17:53:22 nia Exp $

BUILDLINK_TREE+=	plib

.if !defined(PLIB_BUILDLINK3_MK)
PLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plib+=	plib>=1.8.5nb2
BUILDLINK_ABI_DEPENDS.plib+=	plib>=1.8.5nb4
BUILDLINK_PKGSRCDIR.plib?=	../../games/plib
BUILDLINK_DEPMETHOD.plib?=	build

.include "../../graphics/MesaLib/buildlink3.mk"
.endif # PLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-plib
