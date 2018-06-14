# $NetBSD: buildlink3.mk,v 1.2 2018/06/14 12:22:21 youri Exp $

BUILDLINK_TREE+=	colord

.if !defined(COLORD_BUILDLINK3_MK)
COLORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord+=	colord>=1.2.12
BUILDLINK_PKGSRCDIR.colord?=	../../graphics/colord

.endif	# COLORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord
