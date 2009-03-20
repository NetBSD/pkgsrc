# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:34 joerg Exp $

BUILDLINK_TREE+=	plib

.if !defined(PLIB_BUILDLINK3_MK)
PLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plib+=	plib>=1.6.0
BUILDLINK_ABI_DEPENDS.plib?=	plib>=1.6.0nb3
BUILDLINK_PKGSRCDIR.plib?=	../../games/plib
BUILDLINK_DEPMETHOD.plib?=	build

.include "../../graphics/Mesa/buildlink3.mk"
.endif # PLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-plib
