# $NetBSD: buildlink3.mk,v 1.11 2015/04/25 14:23:06 tnn Exp $

BUILDLINK_TREE+=	GUIlib

.if !defined(GUILIB_BUILDLINK3_MK)
GUILIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GUIlib+=	GUIlib>=1.1.0nb2
BUILDLINK_ABI_DEPENDS.GUIlib+=	GUIlib>=1.2.1nb1
BUILDLINK_PKGSRCDIR.GUIlib?=	../../graphics/GUIlib

.include "../../devel/SDL/buildlink3.mk"
.endif # GUILIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-GUIlib
