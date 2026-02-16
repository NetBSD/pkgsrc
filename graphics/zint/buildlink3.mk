# $NetBSD: buildlink3.mk,v 1.1 2026/02/16 13:10:45 wiz Exp $

BUILDLINK_TREE+=	zint

.if !defined(ZINT_BUILDLINK3_MK)
ZINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zint+=	zint>=2.13.0nb10
BUILDLINK_PKGSRCDIR.zint?=	../../graphics/zint

.include "../../graphics/png/buildlink3.mk"
.endif	# ZINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-zint
