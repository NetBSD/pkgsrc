# $NetBSD: buildlink3.mk,v 1.2 2023/05/14 16:11:22 tsutsui Exp $

BUILDLINK_TREE+=	lhasa

.if !defined(LHASA_BUILDLINK3_MK)
LHASA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lhasa+=	lhasa>=0.4.0
BUILDLINK_PKGSRCDIR.lhasa?=	../../archivers/lhasa
.endif	# LHASA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lhasa
