# $NetBSD: buildlink3.mk,v 1.5 2025/06/12 06:31:05 wiz Exp $

BUILDLINK_TREE+=	colord

.if !defined(COLORD_BUILDLINK3_MK)
COLORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord+=	colord>=1.3.5nb7
BUILDLINK_PKGSRCDIR.colord?=	../../graphics/colord

.include "../../graphics/lcms2/buildlink3.mk"
.endif	# COLORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-colord
