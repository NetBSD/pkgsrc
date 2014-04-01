# $NetBSD: buildlink3.mk,v 1.11 2014/04/01 08:38:35 adam Exp $

BUILDLINK_TREE+=	glpk

.if !defined(GLPK_BUILDLINK3_MK)
GLPK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpk+=	glpk>=4.8nb1
BUILDLINK_ABI_DEPENDS.glpk+=	glpk>=4.35nb1
BUILDLINK_PKGSRCDIR.glpk?=	../../math/glpk

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # GLPK_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpk
