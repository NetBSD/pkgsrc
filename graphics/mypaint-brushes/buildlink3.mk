# $NetBSD: buildlink3.mk,v 1.3 2020/03/06 13:46:27 tnn Exp $

BUILDLINK_TREE+=	mypaint-brushes

.if !defined(MYPAINT_BRUSHES_BUILDLINK3_MK)
MYPAINT_BRUSHES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mypaint-brushes+=	mypaint-brushes>=2.0
BUILDLINK_PKGSRCDIR.mypaint-brushes?=	../../graphics/mypaint-brushes
.endif	# MYPAINT_BRUSHES_BUILDLINK3_MK

BUILDLINK_TREE+=	-mypaint-brushes
