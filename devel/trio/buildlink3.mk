# $NetBSD: buildlink3.mk,v 1.1 2020/05/12 09:33:58 nia Exp $

BUILDLINK_TREE+=	trio

.if !defined(TRIO_BUILDLINK3_MK)
TRIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.trio+=	trio>=1.12
BUILDLINK_PKGSRCDIR.trio?=	../../devel/trio
.endif	# TRIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-trio
