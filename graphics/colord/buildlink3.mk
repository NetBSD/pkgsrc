# $NetBSD: buildlink3.mk,v 1.4 2020/10/31 13:29:41 bsiegert Exp $

BUILDLINK_TREE+=	colord

.if !defined(COLORD_BUILDLINK3_MK)
COLORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.colord+=	colord>=1.3.5nb7
BUILDLINK_PKGSRCDIR.colord?=	../../graphics/colord

.endif	# COLORD_BUILDLINK3_MK

.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_TREE+=	-colord
