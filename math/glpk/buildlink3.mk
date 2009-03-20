# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	glpk

.if !defined(GLPK_BUILDLINK3_MK)
GLPK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpk+=	glpk>=4.8nb1
BUILDLINK_ABI_DEPENDS.glpk+=	glpk>=4.9nb1
BUILDLINK_PKGSRCDIR.glpk?=	../../math/glpk

.include "../../devel/gmp/buildlink3.mk"
.endif # GLPK_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpk
