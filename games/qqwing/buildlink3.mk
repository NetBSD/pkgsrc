# $NetBSD: buildlink3.mk,v 1.1 2014/11/29 13:42:30 prlw1 Exp $

BUILDLINK_TREE+=	qqwing

.if !defined(QQWING_BUILDLINK3_MK)
QQWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qqwing+=	qqwing>=1.3.3
BUILDLINK_PKGSRCDIR.qqwing?=	../../games/qqwing
.endif	# QQWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-qqwing
