# $NetBSD: buildlink3.mk,v 1.1 2018/04/30 04:56:17 ryoon Exp $

BUILDLINK_TREE+=	mypaint-brushes-mypaint-brushes

.if !defined(MYPAINT_BRUSHES_MYPAINT_BRUSHES_BUILDLINK3_MK)
MYPAINT_BRUSHES_MYPAINT_BRUSHES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mypaint-brushes-mypaint-brushes+=	mypaint-brushes-mypaint-brushes>=1.3.0
BUILDLINK_PKGSRCDIR.mypaint-brushes-mypaint-brushes?=	../../graphics/mypaint-brushes
.endif	# MYPAINT_BRUSHES_MYPAINT_BRUSHES_BUILDLINK3_MK

BUILDLINK_TREE+=	-mypaint-brushes-mypaint-brushes
