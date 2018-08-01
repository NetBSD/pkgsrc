# $NetBSD: buildlink3.mk,v 1.3 2018/08/01 21:00:09 youri Exp $

BUILDLINK_TREE+=	colord

.if !defined(COLORD_BUILDLINK3_MK)
COLORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord+=	colord>=1.2.12
BUILDLINK_PKGSRCDIR.colord?=	../../graphics/colord

.endif	# COLORD_BUILDLINK3_MK

.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_TREE+=	-colord
