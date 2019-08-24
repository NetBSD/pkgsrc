# $NetBSD: buildlink3.mk,v 1.2 2019/08/24 22:14:13 alnsn Exp $

BUILDLINK_TREE+=	yices2

.if !defined(YICES2_BUILDLINK3_MK)
YICES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yices2+=	yices2>=2.6.1
BUILDLINK_ABI_DEPENDS.yices2+=	yices2>=2.6.1
BUILDLINK_PKGSRCDIR.yices2?=	../../math/yices2

.include "../../devel/gmp/buildlink3.mk"
.endif # YICES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-yices2
