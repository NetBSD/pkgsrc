# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:35 joerg Exp $

BUILDLINK_TREE+=	GUIlib

.if !defined(GUILIB_BUILDLINK3_MK)
GUILIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GUIlib+=	GUIlib>=1.1.0nb2
BUILDLINK_ABI_DEPENDS.GUIlib+=	GUIlib>=1.1.0nb7
BUILDLINK_PKGSRCDIR.GUIlib?=	../../graphics/GUIlib

.include "../../devel/SDL/buildlink3.mk"
.endif # GUILIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-GUIlib
