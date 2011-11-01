# $NetBSD: buildlink3.mk,v 1.3 2011/11/01 06:01:25 sbd Exp $
#

BUILDLINK_TREE+=	agg

.if !defined(AGG_BUILDLINK3_MK)
AGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.agg+=	agg>=2.5
BUILDLINK_ABI_DEPENDS.agg?=	agg>=2.5nb1
BUILDLINK_PKGSRCDIR.agg?=	../../graphics/agg

.include "../../graphics/freetype2/buildlink3.mk"
.endif # AGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-agg
