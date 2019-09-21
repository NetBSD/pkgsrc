# $NetBSD: buildlink3.mk,v 1.1 2019/09/21 11:14:23 nia Exp $

BUILDLINK_TREE+=	lhasa

.if !defined(LHASA_BUILDLINK3_MK)
LHASA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lhasa+=	lhasa>=0.3.1
BUILDLINK_PKGSRCDIR.lhasa?=	../../archivers/lhasa
.endif	# LHASA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lhasa
