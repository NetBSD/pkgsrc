# $NetBSD: buildlink3.mk,v 1.8 2023/11/12 13:21:50 wiz Exp $
#

BUILDLINK_TREE+=	agg

.if !defined(AGG_BUILDLINK3_MK)
AGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.agg+=	agg>=2.5
BUILDLINK_ABI_DEPENDS.agg+=	agg>=2.5nb7
BUILDLINK_PKGSRCDIR.agg?=	../../graphics/agg

.include "../../graphics/freetype2/buildlink3.mk"
.endif # AGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-agg
