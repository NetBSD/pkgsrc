# $NetBSD: buildlink3.mk,v 1.1 2023/05/03 16:56:31 nikita Exp $

BUILDLINK_TREE+=	rapidcheck

.if !defined(RAPIDCHECK_BUILDLINK3_MK)
RAPIDCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rapidcheck+=	rapidcheck>=0.0.0.20220314
BUILDLINK_PKGSRCDIR.rapidcheck?=	../../devel/rapidcheck
.endif	# RAPIDCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-rapidcheck
