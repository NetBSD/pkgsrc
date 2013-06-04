# $NetBSD: buildlink3.mk,v 1.6 2013/06/04 22:16:13 tron Exp $
#

BUILDLINK_TREE+=	agg

.if !defined(AGG_BUILDLINK3_MK)
AGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.agg+=	agg>=2.5
BUILDLINK_ABI_DEPENDS.agg+=	agg>=2.5nb3
BUILDLINK_PKGSRCDIR.agg?=	../../graphics/agg

.include "../../graphics/freetype2/buildlink3.mk"
.endif # AGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-agg
