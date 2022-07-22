# $NetBSD: buildlink3.mk,v 1.1 2022/07/22 22:08:59 wiz Exp $

BUILDLINK_TREE+=	mypaint-brushes1

.if !defined(MYPAINT_BRUSHES1_BUILDLINK3_MK)
MYPAINT_BRUSHES1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mypaint-brushes1+=	mypaint-brushes1>=1.0
BUILDLINK_PKGSRCDIR.mypaint-brushes1?=		../../graphics/mypaint-brushes1
.endif	# MYPAINT_BRUSHES1_BUILDLINK3_MK

BUILDLINK_TREE+=	-mypaint-brushes1
