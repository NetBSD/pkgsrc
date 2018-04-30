# $NetBSD: buildlink3.mk,v 1.2 2018/04/30 20:57:04 wiz Exp $

BUILDLINK_TREE+=	mypaint-brushes

.if !defined(MYPAINT_BRUSHES_BUILDLINK3_MK)
MYPAINT_BRUSHES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mypaint-brushes+=	mypaint-brushes>=1.3.0
BUILDLINK_PKGSRCDIR.mypaint-brushes?=	../../graphics/mypaint-brushes
.endif	# MYPAINT_BRUSHES_BUILDLINK3_MK

BUILDLINK_TREE+=	-mypaint-brushes
