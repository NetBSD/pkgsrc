# $NetBSD: buildlink3.mk,v 1.1 2021/02/06 06:41:33 ryoon Exp $

BUILDLINK_TREE+=	box2d

.if !defined(BOX2D_BUILDLINK3_MK)
BOX2D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.box2d+=	box2d>=2.4.1
BUILDLINK_PKGSRCDIR.box2d?=	../../graphics/box2d

.endif	# BOX2D_BUILDLINK3_MK

BUILDLINK_TREE+=	-box2d
