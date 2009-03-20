# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:36 joerg Exp $
#

BUILDLINK_TREE+=	agg

.if !defined(AGG_BUILDLINK3_MK)
AGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.agg+=	agg>=2.5
BUILDLINK_PKGSRCDIR.agg?=	../../graphics/agg

.include "../../graphics/freetype2/buildlink3.mk"
.endif # AGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-agg
